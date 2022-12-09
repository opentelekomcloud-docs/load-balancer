:original_name: en-us_topic_0287737145.html

.. _en-us_topic_0287737145:

Specifications of Dedicated Load Balancers
==========================================

Dedicated load balancers are available in different specifications. Each specification contains dimensions you can use to decide whether the specification meets your needs. When the traffic exceeds the selected specifications, new requests will not be routed, and packet loss will occur.

-  Maximum connections

   The dimension measures the maximum number of concurrent connections that a load balancer can handle. If the number of connections reaches that defined in the specification, new requests will be discarded to ensure the performance of existing connections.

-  Connections per second (CPS)

   CPS refers to the number of new connections that a load balancer establishes with clients per second. If the number reaches that defined in the specification, new requests will be discarded to ensure the performance of established connections.

   When HTTPS listeners are establishing connections with clients, SSL handshakes occupy more system resources. The number of new HTTPS connections per second is only 10% of the number of new HTTP connections per second. For example, if the specification of a load balancer is small I, and the number of new HTTP connections is 10,000, the number of new HTTPS connections per second is 1,000.

-  Queries per second (QPS)

   QPS measures the number of HTTP or HTTPS requests sent to a backend server per second. If the QPS reaches that defined in the specification, new requests will be discarded to ensure the performance of established connections.

:ref:`Table 1 <en-us_topic_0287737145__table14428152722818>` and :ref:`Table 2 <en-us_topic_0287737145__table201281815505>` list the specifications of dedicated load balancers. **(Available specifications may vary depending on the resources in different regions.)**

.. caution::

   The load balancing type cannot be changed after being selected.

   For example, after you have selected network load balancing, you cannot change it to application load balancing. If you select only network load balancing, you can add only TCP and UDP listeners to the load balancer and cannot add HTTP and HTTPS listeners.

.. _en-us_topic_0287737145__table14428152722818:

.. table:: **Table 1** Specifications for network load balancing (TCP/UDP)

   +-----------+---------------------+---------+--------------------+-------------------------+
   | Type      | Maximum Connections | CPS     | Bandwidth (Mbit/s) | Number of LCUs in an AZ |
   +===========+=====================+=========+====================+=========================+
   | Small I   | 500,000             | 10,000  | 50                 | 10                      |
   +-----------+---------------------+---------+--------------------+-------------------------+
   | Small II  | 1,000,000           | 20,000  | 100                | 20                      |
   +-----------+---------------------+---------+--------------------+-------------------------+
   | Medium I  | 2,000,000           | 40,000  | 200                | 40                      |
   +-----------+---------------------+---------+--------------------+-------------------------+
   | Medium II | 4,000,000           | 80,000  | 400                | 80                      |
   +-----------+---------------------+---------+--------------------+-------------------------+
   | Large I   | 10000000            | 200,000 | 1,000              | 200                     |
   +-----------+---------------------+---------+--------------------+-------------------------+
   | Large II  | 20000000            | 400,000 | 2,000              | 400                     |
   +-----------+---------------------+---------+--------------------+-------------------------+

.. _en-us_topic_0287737145__table201281815505:

.. table:: **Table 2** Specifications for application load balancing (HTTP/HTTPS)

   +-----------+---------------------+------------+-------------+------------+-------------+--------------------+-------------------------+
   | Type      | Maximum Connections | CPS (HTTP) | CPS (HTTPS) | QPS (HTTP) | QPS (HTTPS) | Bandwidth (Mbit/s) | Number of LCUs in an AZ |
   +===========+=====================+============+=============+============+=============+====================+=========================+
   | Small I   | 200,000             | 2,000      | 200         | 4,000      | 2,000       | 50                 | 10                      |
   +-----------+---------------------+------------+-------------+------------+-------------+--------------------+-------------------------+
   | Small II  | 400,000             | 4,000      | 400         | 8,000      | 4,000       | 100                | 20                      |
   +-----------+---------------------+------------+-------------+------------+-------------+--------------------+-------------------------+
   | Medium I  | 800,000             | 8,000      | 800         | 16,000     | 8,000       | 200                | 40                      |
   +-----------+---------------------+------------+-------------+------------+-------------+--------------------+-------------------------+
   | Medium II | 2,000,000           | 20,000     | 2,000       | 40,000     | 20,000      | 400                | 100                     |
   +-----------+---------------------+------------+-------------+------------+-------------+--------------------+-------------------------+
   | Large I   | 4,000,000           | 40,000     | 4,000       | 80,000     | 40,000      | 1,000              | 200                     |
   +-----------+---------------------+------------+-------------+------------+-------------+--------------------+-------------------------+
   | Large II  | 8,000,000           | 80,000     | 8,000       | 160,000    | 80,000      | 2,000              | 400                     |
   +-----------+---------------------+------------+-------------+------------+-------------+--------------------+-------------------------+

.. note::

   -  If you add multiple listeners to a load balancer, the sum of QPS values of all listeners cannot exceed the QPS defined in each specification.
   -  The bandwidth is the upper limit of the total of the inbound traffic and outbound traffic. For example, for small I, the total of the inbound and outbound traffic is less than or equal to 50 Mbit/s.
   -  The bandwidth included in each specification is the maximum bandwidth provided by ELB. If the bandwidth exceeds this dimension, the network performance may be affected.
