:original_name: en-us_topic_0287737145.html

.. _en-us_topic_0287737145:

Specifications of Dedicated Load Balancers
==========================================

When you create a dedicated load balancer, you can select elastic or fixed specifications based on your service requirements. :ref:`Table 1 <en-us_topic_0287737145__en-us_topic_0000001819323754_table5935613662>` compares the two types of specifications.

If the traffic exceeds the selected specifications, new requests will be discarded. Select the specifications based on your service requirements.

.. _en-us_topic_0287737145__en-us_topic_0000001819323754_table5935613662:

.. table:: **Table 1** Specifications comparison

   +----------------------------------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Item                                               | Elastic                                                                                                                                                                                      | Fixed                                                                                                                                                                                        |
   +====================================================+==============================================================================================================================================================================================+==============================================================================================================================================================================================+
   | Application scenarios                              | -  For fluctuating traffic                                                                                                                                                                   | -  For stable traffic                                                                                                                                                                        |
   |                                                    | -  When you need to use resources temporarily and for urgent purposes                                                                                                                        | -  When you need to use resources for a long term                                                                                                                                            |
   +----------------------------------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Network (TCP/UDP) load balancer performance        | The performance multiplies as the number of AZs increases. :ref:`Table 3 <en-us_topic_0287737145__en-us_topic_0000001819323754_table52091547185916>` shows the maximum performance in an AZ. | The performance multiplies as the number of AZs increases. :ref:`Table 6 <en-us_topic_0287737145__en-us_topic_0000001819323754_table14428152722818>` shows the maximum performance in an AZ. |
   +----------------------------------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Application (HTTP/HTTPS) load balancer performance | The performance multiplies as the number of AZs increases. :ref:`Table 3 <en-us_topic_0287737145__en-us_topic_0000001819323754_table52091547185916>` shows the maximum performance in an AZ. | The performance multiplies as the number of AZs increases. :ref:`Table 7 <en-us_topic_0287737145__en-us_topic_0000001819323754_table201281815505>` shows the maximum performance in an AZ.   |
   +----------------------------------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Billing items                                      | -  LCU                                                                                                                                                                                       | LCU                                                                                                                                                                                          |
   |                                                    | -  Load balancer                                                                                                                                                                             |                                                                                                                                                                                              |
   +----------------------------------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Capabilities                                       | Same                                                                                                                                                                                         |                                                                                                                                                                                              |
   +----------------------------------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Elastic Specifications
----------------------

If your service traffic fluctuates greatly, you can choose elastic specifications and select network load balancing (TCP/UDP) or application load balancing (HTTP/HTTPS), or both that best meet your service needs.

.. note::

   The listener protocol must match the load balancing type. For example, if you select application load balancing (HTTP/HTTPS), you can only add an HTTP or HTTPS listener to this load balancer.

:ref:`Table 2 <en-us_topic_0287737145__en-us_topic_0000001819323754_table12368131594417>` describes the dimensions about elastic specifications. When your traffic exceeds the specifications defined in :ref:`Table 3 <en-us_topic_0287737145__en-us_topic_0000001819323754_table52091547185916>`, new requests will be discarded.

.. _en-us_topic_0287737145__en-us_topic_0000001819323754_table12368131594417:

.. table:: **Table 2** Elastic specification dimensions

   +------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Maximum Connections          | Indicates the maximum number of concurrent connections that a load balancer can handle per minute. If the number reaches the maximum connections that is defined in the elastic specifications, new requests will be discarded to ensure the performance of established connections. |
   +------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Connections Per Second (CPS) | Indicates the number of new connections that a load balancer can establish per second. If the number reaches the CPS that is defined in the elastic specifications, new requests will be discarded to ensure the performance of established connections.                             |
   +------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Queries Per Second (QPS)     | Indicates the number of HTTP or HTTPS requests sent to a backend server per second. If the QPS reaches that is defined in the elastic specifications, new requests will be discarded to ensure the performance of established connections.                                           |
   +------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Bandwidth (Mbit/s)           | Indicates the maximum amount of data that can be transmitted over a connection per second.                                                                                                                                                                                           |
   +------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _en-us_topic_0287737145__en-us_topic_0000001819323754_table52091547185916:

.. table:: **Table 3** Maximum elastic specifications

   +------------------------------------+---------------------+---------+---------+--------------------+
   | Protocol                           | Maximum Connections | CPS     | QPS     | Bandwidth (Mbit/s) |
   +====================================+=====================+=========+=========+====================+
   | Network load balancing (TCP/UDP)   | 20,000,000          | 400,000 | N/A     | 10,000             |
   +------------------------------------+---------------------+---------+---------+--------------------+
   | Application load balancing (HTTP)  | 8,000,000           | 80,000  | 160,000 | 10,000             |
   +------------------------------------+---------------------+---------+---------+--------------------+
   | Application load balancing (HTTPS) | 8,000,000           | 80,000  | 160,000 | 10,000             |
   +------------------------------------+---------------------+---------+---------+--------------------+

Fixed Specifications
--------------------

Load balancers are available in different fixed specifications. Choose the specifications that best meet your needs. When your traffic exceeds what defined in your selected specifications, new requests will be discarded. Each specification has the following dimensions.

.. table:: **Table 4** Fixed specification dimensions

   +-----------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Maximum Connections               | Indicates the maximum number of concurrent connections that a load balancer can handle per minute. If the number reaches the maximum connections that is defined in your selected fixed specifications, new requests will be discarded to ensure the performance of existing connections.                                                                                                                                     |
   +-----------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | CPS                               | Indicates the number of new connections that a load balancer can establish per second. If the number reaches the CPS that is defined in your selected fixed specifications, new requests will be discarded to ensure the performance of established connections.                                                                                                                                                              |
   |                                   |                                                                                                                                                                                                                                                                                                                                                                                                                               |
   |                                   | HTTPS listeners need to create SSL handshakes to establish connections with clients, and such SSL handshakes occupy more system resources than HTTP listeners. For example, a small I application load balancer can establish 2,000 new HTTP connections per second but only 200 new HTTPS connections per second. For details, see :ref:`Table 5 <en-us_topic_0287737145__en-us_topic_0000001819323754_table8443434175610>`. |
   +-----------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | QPS                               | Indicates the number of HTTP or HTTPS requests sent to a backend server per second. If the QPS reaches that is defined in your selected fixed specifications, new requests will be discarded to ensure the performance of established connections.                                                                                                                                                                            |
   +-----------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Bandwidth (Mbit/s)                | Indicates the maximum amount of data that can be transmitted over a connection per second.                                                                                                                                                                                                                                                                                                                                    |
   +-----------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

For a small I application load balancer:

-  If you only add an HTTP listener, the load balancer can establish up to 2,000 new HTTP connections.

-  If you only add an HTTPS listener, the load balancer can establish up to 200 new HTTPS connections.

-  If you add an HTTPS listener and an HTTP listener, the new connections are calculated using the following formula:

   New connections = New HTTP connections + New HTTPS connections x Ratio of HTTP connections to HTTPS connections

   For a small I application load balancer, the ratio of HTTP connections to HTTPS connections is 10. For details, see :ref:`Table 5 <en-us_topic_0287737145__en-us_topic_0000001819323754_table8443434175610>`.

   .. _en-us_topic_0287737145__en-us_topic_0000001819323754_table8443434175610:

   .. table:: **Table 5** New connections that a small I application load balancer can establish

      +--------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------+
      | Parameter                      | Scenario 1                                                                                                                                      | Scenario 2                                                                                                                           |
      +================================+=================================================================================================================================================+======================================================================================================================================+
      | New HTTP connections           | 1,000                                                                                                                                           | 1,000                                                                                                                                |
      +--------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------+
      | New HTTPS connections          | 50                                                                                                                                              | 150                                                                                                                                  |
      +--------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------+
      | New HTTP and HTTPS connections | 1,000 + 50 x 10 = 1,500                                                                                                                         | 1,000 + 150 x 10 = 2,500                                                                                                             |
      +--------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------+
      | Description                    | -  The new connections do not reach the CPS (HTTP) that a small I application load balancer can handle, so new requests can be properly routed. | -  The new connections exceed the CPS (HTTP) that a small I application load balancer can handle, so new requests will be discarded. |
      +--------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------+

   .. note::

      Details in the :ref:`Table 5 <en-us_topic_0287737145__en-us_topic_0000001819323754_table8443434175610>` are for reference only.

:ref:`Table 6 <en-us_topic_0287737145__en-us_topic_0000001819323754_table14428152722818>` and :ref:`Table 7 <en-us_topic_0287737145__en-us_topic_0000001819323754_table201281815505>` list the fixed specifications of dedicated load balancers.

.. _en-us_topic_0287737145__en-us_topic_0000001819323754_table14428152722818:

.. table:: **Table 6** Fixed specifications for a network load balancer (TCP/UDP)

   ========= =================== ======= ================== =============
   Type      Maximum Connections CPS     Bandwidth (Mbit/s) LCUs in an AZ
   ========= =================== ======= ================== =============
   Small I   500,000             10,000  50                 10
   Small II  1,000,000           20,000  100                20
   Medium I  2,000,000           40,000  200                40
   Medium II 4,000,000           80,000  400                80
   Large I   10,000,000          200,000 1,000              200
   Large II  20,000,000          400,000 2,000              400
   ========= =================== ======= ================== =============

.. _en-us_topic_0287737145__en-us_topic_0000001819323754_table201281815505:

.. table:: **Table 7** Fixed specifications for an application load balancer (HTTP/HTTPS)

   +-----------+---------------------+------------+-------------+------------+-------------+--------------------+---------------+
   | Type      | Maximum Connections | CPS (HTTP) | CPS (HTTPS) | QPS (HTTP) | QPS (HTTPS) | Bandwidth (Mbit/s) | LCUs in an AZ |
   +===========+=====================+============+=============+============+=============+====================+===============+
   | Small I   | 200,000             | 2,000      | 200         | 4,000      | 2,000       | 50                 | 10            |
   +-----------+---------------------+------------+-------------+------------+-------------+--------------------+---------------+
   | Small II  | 400,000             | 4,000      | 400         | 8,000      | 4,000       | 100                | 20            |
   +-----------+---------------------+------------+-------------+------------+-------------+--------------------+---------------+
   | Medium I  | 800,000             | 8,000      | 800         | 16,000     | 8,000       | 200                | 40            |
   +-----------+---------------------+------------+-------------+------------+-------------+--------------------+---------------+
   | Medium II | 2,000,000           | 20,000     | 2,000       | 40,000     | 20,000      | 400                | 100           |
   +-----------+---------------------+------------+-------------+------------+-------------+--------------------+---------------+
   | Large I   | 4,000,000           | 40,000     | 4,000       | 80,000     | 40,000      | 1,000              | 200           |
   +-----------+---------------------+------------+-------------+------------+-------------+--------------------+---------------+
   | Large II  | 8,000,000           | 80,000     | 8,000       | 160,000    | 80,000      | 2,000              | 400           |
   +-----------+---------------------+------------+-------------+------------+-------------+--------------------+---------------+

.. note::

   -  If you add multiple listeners to a load balancer, the sum of QPS values of all listeners cannot exceed the QPS defined in each specification.
   -  The bandwidth is the upper limit of the inbound or the outbound traffic. For example, for small I load balancers, the inbound or outbound traffic cannot exceed 50 Mbit/s.
   -  The bandwidth included in each specification is the maximum bandwidth provided by ELB. If the maximum bandwidth is exceeded, the network performance may be affected.
