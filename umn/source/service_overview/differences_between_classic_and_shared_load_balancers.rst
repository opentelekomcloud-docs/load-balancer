Differences Between Classic and Shared Load Balancers
=====================================================

Each type of load balancer has their advantages.

-  Classic load balancers are suitable for web services with low traffic and simple traffic patterns.\ |image1|

   Classic load balancers can no longer be created on the management console. Use shared load balancers or dedicated load balancers instead.

-  Shared load balancers are suitable for choices for web services with heavy traffic. (Shared load balancers were previously named enhanced load balancers.)

`Table 1 <#en-us_elb_01_0007__table4688103612223>`__ compares the features supported by the two types of load balancers. Y indicates that an item is supported, and — indicates that an item is not supported.



.. _en-us_elb_01_0007__table4688103612223:

.. table:: **Table 1** Features supported by each type of load balancers

   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Feature                     | Description                 | Classic                     | Shared                      |
   +=============================+=============================+=============================+=============================+
   | Load balancing over public  | -  Each load balancer on a  | Y                           | Y                           |
   | and private networks        |    public network has a     |                             |                             |
   |                             |    public IP address bound  |                             |                             |
   |                             |    to it and routes         |                             |                             |
   |                             |    requests from clients to |                             |                             |
   |                             |    backend servers over the |                             |                             |
   |                             |    Internet.                |                             |                             |
   |                             | -  Load balancers on a      |                             |                             |
   |                             |    private network work     |                             |                             |
   |                             |    within a VPC and route   |                             |                             |
   |                             |    requests from clients to |                             |                             |
   |                             |    backend servers in the   |                             |                             |
   |                             |    same VPC.                |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Layer 4 and Layer 7 load    | -  Layer 4 load balancing:  | Y (UDP is not supported for | Y                           |
   | balancing                   |    After receiving TCP or   | load balancers on a private |                             |
   |                             |    UDP requests from the    | network.)                   |                             |
   |                             |    clients, the load        |                             |                             |
   |                             |    balancer directly routes |                             |                             |
   |                             |    the requests to backend  |                             |                             |
   |                             |    servers. Load balancing  |                             |                             |
   |                             |    at Layer 4 features high |                             |                             |
   |                             |    routing efficiency.      |                             |                             |
   |                             | -  Layer 7 load balancing:  |                             |                             |
   |                             |    After receiving an HTTP  |                             |                             |
   |                             |    or HTTPS request, the    |                             |                             |
   |                             |    load balancer identifies |                             |                             |
   |                             |    the fields in the        |                             |                             |
   |                             |    HTTP/HTTPS packet header |                             |                             |
   |                             |    and routes the request   |                             |                             |
   |                             |    based on these fields.   |                             |                             |
   |                             |    Though the routing       |                             |                             |
   |                             |    efficiency is lower than |                             |                             |
   |                             |    that at Layer 4, load    |                             |                             |
   |                             |    balancing at Layer 7     |                             |                             |
   |                             |    provides some advanced   |                             |                             |
   |                             |    features such as         |                             |                             |
   |                             |    encrypted transmission   |                             |                             |
   |                             |    and cookie-based sticky  |                             |                             |
   |                             |    sessions.                |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Load balancing algorithm    | Round robin, least          | Y                           | Y                           |
   |                             | connections, and source IP  |                             |                             |
   |                             | hash                        |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Sticky session              | If you enable sticky        | Y                           | Y                           |
   |                             | sessions, requests from the |                             |                             |
   |                             | same client will be routed  |                             |                             |
   |                             | to the same backend server  |                             |                             |
   |                             | during the session.         |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | WebSocket protocol          | WebSocket is a new HTML5    | Y                           | Y                           |
   |                             | protocol that provides      |                             |                             |
   |                             | full-duplex communication   |                             |                             |
   |                             | between the browser and the |                             |                             |
   |                             | server. WebSocket saves     |                             |                             |
   |                             | server resources and        |                             |                             |
   |                             | bandwidth, and enables      |                             |                             |
   |                             | real-time communication.    |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Domain name- or URL-based   | ELB allows you to add       | —                           | Y (Currently, you can add   |
   | forwarding                  | forwarding policies to      |                             | forwarding policies only to |
   |                             | forward requests to         |                             | HTTP or HTTPS listeners.)   |
   |                             | different backend server    |                             |                             |
   |                             | groups based on the domain  |                             |                             |
   |                             | names or URLs specified in  |                             |                             |
   |                             | the forwarding policies.    |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Adding ECSs as backend      | You can add ECSs to backend | Y                           | Y                           |
   | servers                     | server groups to handle     |                             |                             |
   |                             | requests from load          |                             |                             |
   |                             | balancers.                  |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Whitelist-based access      | You can whitelist the IP    | —                           | Y                           |
   | control                     | addresses that can access a |                             |                             |
   |                             | listener.                   |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Standard OpenStack APIs     | OpenStack APIs are          | —                           | Y                           |
   |                             | supported and are           |                             |                             |
   |                             | compatible with             |                             |                             |
   |                             | self-developed APIs.        |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Adding BMSs as backend      | BMSs can also be used as    | —                           | Y                           |
   | servers                     | backend servers to handle   |                             |                             |
   |                             | requests distributed by     |                             |                             |
   |                             | load balancers.             |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | SNI for certificates        | Server Name Indication      | Y                           | Y                           |
   |                             | (SNI) is an extension to    |                             |                             |
   |                             | Transport Layer Security    |                             |                             |
   |                             | (TLS) and is used in cases  |                             |                             |
   |                             | that a server uses multiple |                             |                             |
   |                             | domain names and            |                             |                             |
   |                             | certificates. After SNI is  |                             |                             |
   |                             | enabled, certificates       |                             |                             |
   |                             | corresponding to the domain |                             |                             |
   |                             | names are required.         |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | SSL protocol                | Load balancers use SSL to   | Y                           | —                           |
   |                             | receive requests from       |                             |                             |
   |                             | clients.                    |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | OBS storage for access logs | Access logs of load         | Y                           | —                           |
   |                             | balancers can be dumped to  |                             |                             |
   |                             | OBS buckets for storage.    |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Server weight               | You can configure different | —                           | Y                           |
   |                             | weights for backend servers |                             |                             |
   |                             | when you select the round   |                             |                             |
   |                             | robin or least connections  |                             |                             |
   |                             | as the load balancing       |                             |                             |
   |                             | algorithm.                  |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Modifying certificate       | You can modify the content  | —                           | Y                           |
   | content                     | of a certificate.           |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Mutual authentication       | The identities of both      | —                           | Y                           |
   |                             | communication parties are   |                             |                             |
   |                             | authenticated to ensure     |                             |                             |
   |                             | security. You need to       |                             |                             |
   |                             | deploy both the server      |                             |                             |
   |                             | certificate and client      |                             |                             |
   |                             | certificate. Only HTTPS     |                             |                             |
   |                             | listeners support this      |                             |                             |
   |                             | feature.                    |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | HTTP redirection            | HTTP traffic is redirected  | —                           | Y                           |
   |                             | to HTTPS. When the client   |                             |                             |
   |                             | sends an HTTP request, the  |                             |                             |
   |                             | backend server returns an   |                             |                             |
   |                             | HTTPS response.             |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Performance monitoring on a | Cloud Eye allows you to     | —                           | Y                           |
   | per listener basis          | monitor your resources,     |                             |                             |
   |                             | including load balancers.   |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+

.. |image1| image:: /images/note_3.0-en-us.png
