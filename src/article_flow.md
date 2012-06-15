Title: Destination-irrelevant architecture
Date: 16-03-2012

Today many developers use request-based in everything - it is very easy to think in it, easy to understand, easy to use.
But that happens next? Next we want to do things fast. Here we go for multi threaded program, event-driven programming, use co-routines,
and every single bit we can find to speed this damn thing. And they work too - program speeds up. We see incredible async beasts that
handle tens of thousands requests per second, but how about take a look to another approach in programming?

## Situation

Let's imagine following situation: we have big cluster of computers, and we have big pile of data in it. We setup some db solution to
store this data and retrieve. And this db solution is request-based - we say "i want this data", and server send to to us. Looks good, but
i do not want to store and retrive data only. I want to process it and write it back in another place. And what happens?
Single tiny client request huge pile of data, receive it over network, with some magic and time it process all that data and then send
data back to cluster. Do you see bottleneck?

## Obvious solution

Yes, we can setup more advanced software over cluster to run program over all computers in cluster. Then we need some split data algo,
and it would be good if it use same machine for processing where data stored. Then we need some management software to start our program and
watch how our system do. May be we hire OpenMP guy to make one huge program to run on cluster. And so on.

Too complex, too time-consuming, too costly.

## Less obvious solution

Rethink architecture. May be we can somehow to fix this. What if i do not download all that data, but say there i want it to flow to.
That would be easy - tiny client send request with destination inside, and destination itself is huge processing system which is easy
to build with ZeroMQ. So, in this environment client can download data and use it by himself (an old way), can pass data to another
destination (new way). And even more, that destination can flow resulting data to any destination too. Request can have any number of 
nested destinations. I can even pass some data to client back, i can ask client to solve some specific job and get results back in system.

From higher point of view it would look even better. Lets say "company 1" do X with data, and other "company 2" do Y with data.
We have data and we want to get X(Y(data)). I make request to company 1 to process data and send it to company 2, which in turn
process incoming data and return it to me back. I'm not in middle of 1 and 2, and i would not see that intermediate data and i really do
not want to see or store or retransmit it. That helps to same time and space a bit.

More - company 2 can use our own secret code Z to make Y processing even better. But we do not want to give them Z, nor access to api, nor
pay to them to adapt their code to use our api. With this new architecture i can do it easy (of course company 1 and 2 need to support it too)
I supply temporary zeromq socket to my request, and company 2 see - there is service available - it can use it. Then processing completes -
temporary access closed and no one can use our code.

## Real example

In frozen we can do like that very easy. It use ZeroMQ to build distributed systems, and it can pass sockets inside requests.
Our service in turn see socket in request, unpack it, and use it to send data to next destination.

Code for service A:
[article_flow_servicea.m4][]

Code for service B:
[article_flow_serviceb.m4][]

Code for client:
[article_flow_client.m4][]

We start in different consoles:

	$ frozend -c article_flow_router.m4
	$ frozend -c article_flow_servicea.m4
	$ frozend -c article_flow_serviceb.m4

And run this on client:

	$ frozend -c article_flow_client.m4

In result we see following in service B console:

	$ frozend -c article_flow_serviceb.m4 
	client data: client_data
	service a data: service_a
	service b data: service_b

Here we see data we set in client, data which service A set, and service B.

## Real world

Examples are cool, but can be not so good in real world. However, i use it to run my crawler project. I have crawler as "service A" and html
processing engine as "service B". I can add as many crawlers and process engines in any time i want and shut them down too.
Unfortunately, piece of code for crawler and processing engine would remain closed for a while. Rest of system - frozen and all that distributed
stuff is open-source and you free to use it.

[article_flow_servicea.m4]: https://github.com/x86-64/frozen/blob/master/examples/article_flow_servicea.m4
[article_flow_serviceb.m4]: https://github.com/x86-64/frozen/blob/master/examples/article_flow_serviceb.m4
[article_flow_client.m4]: https://github.com/x86-64/frozen/blob/master/examples/article_flow_client.m4
