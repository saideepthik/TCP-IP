# TCP-IP
HAVE SOME SAMPLE CODES ON CLIENT_SERVER MODEL


TCP/IP, or the Transmission Control Protocol/Internet Protocol, 
        is a suite of communication protocols used to interconnect network devices on the internet. 
                TCP/IP can also be used as a communications protocol in a private network (an intranet or an extranet).
                
TCP/IP specifies how data is exchanged over the internet by providing end-to-end communications that identify how it should be broken into packets, addressed, transmitted, routed and received at the destination. 
TCP/IP requires little central management, and it is designed to make networks reliable, with the ability to recover automatically from the failure of any device on the network.

The two main protocols in the internet protocol suite serve specific functions. 

TCP defines how applications can create channels of communication across a network. 
It also manages how a message is assembled into smaller packets before they are then transmitted over the internet and reassembled in the right order at the destination address.

IP defines how to address and route each packet to make sure it reaches the right destination. 
Each gateway computer on the network checks this IP address to determine where to forward the message.

The client–server model is a distributed application structure that partitions tasks or workloads between the providers of a resource or service, called servers, and service requesters, called clients.
Often clients and servers communicate over a computer network on separate hardware, but both client and server may reside in the same system.

A server host runs one or more server programs which share their resources with clients. 
A client does not share any of its resources, but requests a server's content or service function. 
Clients therefore initiate communication sessions with servers which await incoming requests. 
Examples of computer applications that use the client–server model are Email, network printing, and the World Wide Web.

Client and server communication:

	In general, a service is an abstraction of computer resources and a client does not have to be concerned with how the server performs while fulfilling the request and delivering the response. The client only has to understand the response based on the well-known application protocol, i.e. the content and the formatting of the data for the requested service.

	Clients and servers exchange messages in a request–response messaging pattern. The client sends a request, and the server returns a response. This exchange of messages is an example of inter-process communication. To communicate, the computers must have a common language, and they must follow rules so that both the client and the server know what to expect. The language and rules of communication are defined in a communications protocol. All client-server protocols operate in the application layer. The application layer protocol defines the basic patterns of the dialogue. To formalize the data exchange even further, the server may implement an application programming interface (API). The API is an abstraction layer for accessing a service. By restricting communication to a specific content format, it facilitates parsing. By abstracting access, it facilitates cross-platform data exchange.

	A server may receive requests from many distinct clients in a short period of time. A computer can only perform a limited number of tasks at any moment, and relies on a scheduling system to prioritize incoming requests from clients to accommodate them. To prevent abuse and maximize availability, server software may limit the availability to clients. Denial of service attacks are designed to exploit a server's obligation to process requests by overloading it with excessive request rates.
