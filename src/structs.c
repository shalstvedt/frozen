#include <libfrozen.h>

static int  struct_iter_init(void *p_setting, void *p_structure, void *null){
	size_t    member_id;
	data_type member_data_type;
	char *    member_data_type_s;
	char *    member_name;
	size_t    member_size;
	member_t *members;
	

	member_name        = setting_get_child_string((setting_t *)p_setting, "name");
	member_data_type_s = setting_get_child_string((setting_t *)p_setting, "type");
	member_data_type   = data_type_from_string(member_data_type_s);
	
	if(member_name == NULL || member_data_type_s == NULL || member_data_type < 0)
		return ITER_BREAK;
	
	struct_t *structure = (struct_t *)p_structure;
	
	members             = structure->members;
	member_id           = structure->members_count++;
	members = (member_t *)realloc(members, structure->members_count * sizeof(member_t));
	structure->members  = members;
	
	members[member_id].name      = member_name;
	members[member_id].ptr       = (off_t)structure->size;
	members[member_id].data_type = member_data_type;
	
	member_size = data_len(member_data_type, NULL, 0);
	
	if(member_id == 0 || structure->size != 0)  // count structure size til member size is known
		structure->size += member_size;     // 
	if(member_size == 0)                        // member size not known, stop counting
		structure->size  = 0;               //  
	
	return ITER_CONTINUE;
}

struct_t *  struct_new                   (setting_t *config){
	int       ret;
	struct_t *structure = (struct_t *)malloc(sizeof(struct_t));
	
	memset(structure, 0, sizeof(struct_t));
	
	ret = setting_iter_child(config, (iter_callback)&struct_iter_init, structure, NULL);
	if(ret == ITER_BROKEN){
		struct_free(structure);
		return NULL;
	}
	
	return structure;
}

void        struct_free                  (struct_t *structure){
	if(structure->members != NULL)
		free(structure->members);
	free(structure);
}

member_t *  struct_get_member_by_name    (struct_t *structure, char *name){
	size_t     member_id;
	member_t * members;
	
	members = structure->members;
	for(member_id=0; member_id<structure->members_count; member_id++){
		if(strcmp(members[member_id].name, name) == 0)
			return &(members[member_id]);
	}
	return NULL;
}
inline size_t  struct_get_size              (struct_t *structure){ return structure->size; }

// TODO rewrite to handle buffer having data splitted between two chunks
// TODO SEC dangerous function

int         struct_get_member_value      (struct_t *structure, buffer_t *buffer, unsigned int member_id, subchunk_t *chunk){
	unsigned int   c;
	void          *d_ptr   = NULL;
	off_t          m_ptr   = 0;
	member_t      *members = structure->members;
	
	if(member_id >= structure->members_count)
		return -EINVAL;
	
	m_ptr = members[member_id].ptr;
	
	if(m_ptr == 0 && member_id != 0){
		//c = member_id - 1                        // TODO uncomment to test speedup
		//while(c != 0 && members[c].ptr == NULL)  // scroll back to known pointer
		//	c--;
		//m_ptr = members[c].ptr;
		
		c = 0;
		while(c < member_id){
			d_ptr  = buffer_seek(buffer, m_ptr);
			m_ptr += data_len(members[c].data_type, d_ptr, buffer->size); // TODO SEC invalid buffer size
			
			// TODO add ptr's cache 
			c++;
		}
	}
	
	chunk->ptr  = buffer_seek(buffer, m_ptr);
	chunk->size = data_len(members[member_id].data_type, chunk->ptr, buffer->size); // TODO SEC invalid buffer size
	
	return 0;
}

