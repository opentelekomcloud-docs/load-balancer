Specifications of Dedicated Load Balancers
==========================================

Dedicated load balancers are available in different specifications. Each specification contains some key metrics from which you can decide whether the specification meets your needs. When the traffic exceeds the selected specifications, new requests will not be routed, and packet loss will occur.

-  Maximum connections

   The metric measures the maximum number of concurrent connections that a load balancer can handle. If the number of connections reaches that defined in the specification, new requests will be discarded to ensure the performance of existing connections.

-  Connections per second (CPS)

   CPS refers to the number of new connections that a load balancer establishes with clients per second. If the number reaches that defined in the specification, new requests will be discarded to ensure the performance of established connections.

   When HTTPS listeners are establishing connections with clients, SSL handshakes occupy more system resources. The number of new HTTPS connections per second is only 10% of the number of new HTTP connections per second. For example, if the specification of a load balancer is small I, and the number of new HTTP connections is 10,000, the number of new HTTPS connections per second is 1,000.

-  Queries per second (QPS)

   QPS measures the number of HTTP or HTTPS requests sent to a backend server per second. If the QPS reaches that defined in the specification, new requests will be discarded to ensure the performance of established connections.

`Table 1 <#en-us_topic_0287737145__table14428152722818>`__ and `Table 2 <#en-us_topic_0287737145__table201281815505>`__ list the specifications of dedicated load balancers. **(Available specifications may vary depending on the resources in different regions.)**



.. _en-us_topic_0287737145__table14428152722818:

.. table:: **Table 1** Network load balancing (TCP/UDP)

   ========= =================== ======= ================== =======================
   Type      Maximum Connections CPS     Bandwidth (Mbit/s) Number of LCUs in an AZ
   ========= =================== ======= ================== =======================
   Small I   500,000             10,000  50                 10
   Small II  1,000,000           20,000  100                20
   Medium I  2,000,000           40,000  200                40
   Medium II 4,000,000           80,000  400                80
   Large I   10000000            200,000 1,000              200
   Large II  20000000            400,000 2,000              400
   ========= =================== ======= ================== =======================

.. _en-us_topic_0287737145__table201281815505:

.. table:: **Table 2** Application load balancing (HTTP/HTTPS)

   ========= =================== ========== =========== ======= ================== =======================
   Type      Maximum Connections CPS (HTTP) CPS (HTTPS) QPS     Bandwidth (Mbit/s) Number of LCUs in an AZ
   ========= =================== ========== =========== ======= ================== =======================
   Small I   200,000             2,000      200         4,000   50                 10
   Small II  400,000             4,000      400         8,000   100                20
   Medium I  800,000             8,000      800         16,000  200                40
   Medium II 2,000,000           20,000     2,000       40,000  400                100
   Large I   4,000,000           40,000     4,000       80,000  1,000              200
   Large II  8,000,000           80,000     8,000       160,000 2,000              400
   ========= =================== ========== =========== ======= ================== =======================

|image1|

If you have added multiple listeners to a load balancer, the sum of QPS values of all listeners cannot exceed the QPS defined in each specification.

.. |image1| image:: /images/note_3.0-en-us.png
