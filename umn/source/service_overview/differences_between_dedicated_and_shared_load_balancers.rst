Differences Between Dedicated and Shared Load Balancers
=======================================================

Each type of load balancer has their advantages.

-  Dedicated load balancers have exclusive use of underlying resources, so that the performance of a dedicated load balancer is not affected by other load balancers. In addition, there are a wide range of specifications available for selection.

-  Shared load balancers share underlying resources so that the performance of a load balancer is affected by other load balancers. Shared load balancers were previously named enhanced load balancers.\ |image1|

   Currently, dedicated load balancers are supported only in the **eu-nl** region.

Advantages of Dedicated Load Balancers
--------------------------------------

-  Robust performance

   Each dedicated load balancer has exclusive use of isolated underlying resources and can provide guaranteed performance. A single dedicated load balancer deployed in one AZ can establish up to 20 million concurrent connections, and a load balancer deployed across two AZs can establish up to 40 million concurrent connections, meeting your requirements for handling a massive number of requests.

-  High availability

   Dedicated load balancers provide a comprehensive health check mechanism to ensure that incoming traffic is routed to only healthy backend servers, improving the availability of your applications.

   Dedicated load balancers on both public and private networks can route traffic across AZs and support automatic DR and service isolation between users.

-  Ultra security

   Dedicated load balancers also allow you to select security policies that fit your security requirements.

-  Multiple protocols

   Dedicated load balancers support the following protocols, including TCP, UDP, HTTP, and HTTPS, so that they can route requests from different types of applications.

-  Hybrid load balancing

   Dedicated load balancers can route requests to both servers on the cloud and on premises, allowing you to leverage the public cloud to handle burst traffic.

Feature Comparisons
-------------------

Dedicated load balancers provide more powerful forwarding performance, while shared load balancers are less expensive. You can select the appropriate load balancer based on your application needs. The following tables compare the features supported by the two types of load balancers. (Y indicates that an item is supported, and ╳ indicates that an item is not supported.)



.. _elb_pro_0004__en-us_topic_0000001192971589_table142931939192617:

.. table:: **Table 1** Supported protocols

   +----------------------+-----------------------------------------+--------------------------+-----------------------+
   | Protocol             | Description                             | Dedicated Load Balancers | Shared Load Balancers |
   +======================+=========================================+==========================+=======================+
   | TCP/UDP (Layer 4)    | After receiving TCP or UDP requests     | Y                        | Y                     |
   |                      | from the clients, the load balancer     |                          |                       |
   |                      | directly routes the requests to backend |                          |                       |
   |                      | servers. Load balancing at Layer 4      |                          |                       |
   |                      | features high routing efficiency.       |                          |                       |
   +----------------------+-----------------------------------------+--------------------------+-----------------------+
   | HTTP/HTTPS (Layer 7) | After receiving a request, the listener | Y                        | Y                     |
   |                      | needs to identify the request and       |                          |                       |
   |                      | forward data based on the fields in the |                          |                       |
   |                      | HTTP/HTTPS packet header. Though the    |                          |                       |
   |                      | routing efficiency is lower than that   |                          |                       |
   |                      | at Layer 4, load balancing at Layer 7   |                          |                       |
   |                      | provides some advanced features such as |                          |                       |
   |                      | encrypted transmission and cookie-based |                          |                       |
   |                      | sticky sessions.                        |                          |                       |
   +----------------------+-----------------------------------------+--------------------------+-----------------------+
   | WebSocket            | WebSocket is a new HTML5 protocol that  | Y                        | Y                     |
   |                      | provides full-duplex communication      |                          |                       |
   |                      | between the browser and the server.     |                          |                       |
   |                      | WebSocket saves server resources and    |                          |                       |
   |                      | bandwidth, and enables real-time        |                          |                       |
   |                      | communication.                          |                          |                       |
   +----------------------+-----------------------------------------+--------------------------+-----------------------+



.. _elb_pro_0004__en-us_topic_0000001192971589_table9759549192919:

.. table:: **Table 2** Supported Backend types

   +--------------+-------------------------------------------------+--------------------------+-----------------------+
   | Backend Type | Description                                     | Dedicated Load Balancers | Shared Load Balancers |
   +==============+=================================================+==========================+=======================+
   | ECS          | You can use load balancers to distribute        | Y                        | Y                     |
   |              | incoming traffic across ECSs.                   |                          |                       |
   +--------------+-------------------------------------------------+--------------------------+-----------------------+
   | BMS          | You can use load balancers to distribute        | Y                        | Y                     |
   |              | incoming traffic across BMSs.                   |                          |                       |
   +--------------+-------------------------------------------------+--------------------------+-----------------------+



.. _elb_pro_0004__en-us_topic_0000001192971589_table593918591292:

.. table:: **Table 3** Advanced features

   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Feature                     | Description                 | Dedicated Load Balancers    | Shared Load Balancers       |
   +=============================+=============================+=============================+=============================+
   | Multiple specifications     | Load balancers allow you to | Y                           | x                           |
   |                             | select appropriate          |                             |                             |
   |                             | specifications based on     |                             |                             |
   |                             | your requirements. For      |                             |                             |
   |                             | details, see                |                             |                             |
   |                             | `Specifications of          |                             |                             |
   |                             | Dedicated Load              |                             |                             |
   |                             | Balancers <en-us            |                             |                             |
   |                             | _topic_0287737145.html>`__. |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | HTTPS support               | Load balancers can receive  | Y                           | x                           |
   |                             | HTTPS requests from clients |                             |                             |
   |                             | and route them to backend   |                             |                             |
   |                             | servers.                    |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Mutual authentication       | In this case, you need to   | Y                           | Y                           |
   |                             | deploy both the server      |                             |                             |
   |                             | certificate and client      |                             |                             |
   |                             | certificate.                |                             |                             |
   |                             |                             |                             |                             |
   |                             | Mutual authentication is    |                             |                             |
   |                             | supported only by HTTPS     |                             |                             |
   |                             | listeners.                  |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | SNI                         | Server Name Indication      | Y                           | Y                           |
   |                             | (SNI) is an extension to    |                             |                             |
   |                             | TLS and is used when a      |                             |                             |
   |                             | server uses multiple domain |                             |                             |
   |                             | names and certificates.     |                             |                             |
   |                             | After SNI is enabled,       |                             |                             |
   |                             | certificates corresponding  |                             |                             |
   |                             | to the domain names are     |                             |                             |
   |                             | required.                   |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Security policies           | When you add HTTPS          | Y                           | Y                           |
   |                             | listeners, you can select   |                             |                             |
   |                             | desired security policies   |                             |                             |
   |                             | to improve service          |                             |                             |
   |                             | security. A security policy |                             |                             |
   |                             | is a combination of TLS     |                             |                             |
   |                             | protocols and cipher        |                             |                             |
   |                             | suites.                     |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+



.. _elb_pro_0004__en-us_topic_0000001192971589_table95315574216:

.. table:: **Table 4** Other features

   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Feature                     | Description                 | Dedicated Load Balancers    | Shared Load Balancers       |
   +=============================+=============================+=============================+=============================+
   | Cross-AZ deployment         | You can create a load       | Y                           | x                           |
   |                             | balancer in multiple AZs.   |                             |                             |
   |                             | Each AZ selects an optimal  |                             |                             |
   |                             | path to process requests.   |                             |                             |
   |                             | In addition, the AZs back   |                             |                             |
   |                             | up each other, improving    |                             |                             |
   |                             | service processing          |                             |                             |
   |                             | efficiency and reliability. |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Load balancing algorithms   | Load balancers support      | Y                           | Y                           |
   |                             | weighted round robin,       |                             |                             |
   |                             | weighted least connections, |                             |                             |
   |                             | and source IP hash.         |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
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
   | Modifying the bandwidth     | You can modify the          | Y                           | Y                           |
   |                             | bandwidth used by the EIP   |                             |                             |
   |                             | bound to the load balancer  |                             |                             |
   |                             | as required.                |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Binding/Unbinding an IP     | You can bind an IP address  | Y                           | Y                           |
   | address                     | to a load balancer or       |                             |                             |
   |                             | unbind the IP address from  |                             |                             |
   |                             | a load balancer based on    |                             |                             |
   |                             | service requirements.       |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Sticky session              | If you enable sticky        | Y                           | Y                           |
   |                             | sessions, requests from the |                             |                             |
   |                             | same client will be routed  |                             |                             |
   |                             | to the same backend server  |                             |                             |
   |                             | during the session.         |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Access control              | You can add IP addresses to | Y                           | Y                           |
   |                             | a whitelist or blacklist to |                             |                             |
   |                             | control access to a         |                             |                             |
   |                             | listener.                   |                             |                             |
   |                             |                             |                             |                             |
   |                             | -  A whitelist allows       |                             |                             |
   |                             |    specified IP addresses   |                             |                             |
   |                             |    to access the listener.  |                             |                             |
   |                             | -  A blacklist denies       |                             |                             |
   |                             |    access from specified IP |                             |                             |
   |                             |    addresses.               |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Health check                | Load balancers periodically | Y                           | Y                           |
   |                             | send requests to backend    |                             |                             |
   |                             | servers to check whether    |                             |                             |
   |                             | they can process requests.  |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Certificate management      | You can create two types of | Y                           | Y                           |
   |                             | certificates: server        |                             |                             |
   |                             | certificate and CA          |                             |                             |
   |                             | certificate. If you need an |                             |                             |
   |                             | HTTPS listener, you need to |                             |                             |
   |                             | bind a server certificate   |                             |                             |
   |                             | to it. To enable mutual     |                             |                             |
   |                             | authentication, you also    |                             |                             |
   |                             | need to bind a CA           |                             |                             |
   |                             | certificate to the          |                             |                             |
   |                             | listener. You can also      |                             |                             |
   |                             | replace a certificate that  |                             |                             |
   |                             | is already used by a load   |                             |                             |
   |                             | balancer.                   |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Tagging                     | If you have a large number  | Y                           | Y                           |
   |                             | of cloud resources, you can |                             |                             |
   |                             | assign different tags to    |                             |                             |
   |                             | the resources to quickly    |                             |                             |
   |                             | identify them and use these |                             |                             |
   |                             | tags to easily manage your  |                             |                             |
   |                             | resources.                  |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Support the display of      | You can use Cloud Eye to    | Y                           | Y                           |
   | monitoring metrics.         | monitor load balancers and  |                             |                             |
   |                             | associated resources and    |                             |                             |
   |                             | view metrics on the         |                             |                             |
   |                             | management console.         |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Log auditing                | You can use Cloud Trace     | Y                           | Y                           |
   |                             | Service (CTS) to record     |                             |                             |
   |                             | operations on load          |                             |                             |
   |                             | balancers and associated    |                             |                             |
   |                             | resources for query,        |                             |                             |
   |                             | auditing, and backtracking. |                             |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+

.. |image1| image:: /images/note_3.0-en-us.png
