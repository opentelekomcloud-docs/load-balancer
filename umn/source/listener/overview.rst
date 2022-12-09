:original_name: elb_ug_jt_0001.html

.. _elb_ug_jt_0001:

Overview
========

You need to add at least one listener after you have created a load balancer. This listener receives requests from clients and routes requests to backend servers using the protocol, port, and load balancing algorithm you select.

Supported Protocols
-------------------

ELB provides load balancing at both Layer 4 and Layer 7.

Select TCP or UDP for load balancing at Layer 4 and HTTP or HTTPS at Layer 7.

.. _elb_ug_jt_0001__table66244785114429:

.. table:: **Table 1** Protocols supported by ELB

   +-----------------+-----------------+----------------------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------+
   | Protocol        |                 | Description                                                                            | Application Scenario                                                                                         |
   +=================+=================+========================================================================================+==============================================================================================================+
   | Layer 4         | TCP             | -  Source IP address-based sticky sessions                                             | -  Scenarios that require high reliability and data accuracy, such as file transfer, email, and remote login |
   |                 |                 | -  Fast data transfer                                                                  | -  Web applications that receive a large number of concurrent requests and require high performance          |
   +-----------------+-----------------+----------------------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------+
   | Layer 4         | UDP             | -  Low reliability                                                                     | Scenarios that require quick response, such as video chat, gaming, and real-time financial quotations        |
   |                 |                 | -  Fast data transfer                                                                  |                                                                                                              |
   +-----------------+-----------------+----------------------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------+
   | Layer 7         | HTTP            | -  Cookie-based sticky sessions                                                        | Web applications where data content needs to be identified, such as mobile games                             |
   |                 |                 | -  X-Forward-For request header                                                        |                                                                                                              |
   +-----------------+-----------------+----------------------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------+
   | Layer 7         | HTTPS           | -  An extension of HTTP for encrypted data transmission to prevent unauthorized access | Web applications that require encrypted transmission                                                         |
   |                 |                 | -  Encryption and decryption performed on load balancers                               |                                                                                                              |
   |                 |                 | -  Multiple versions of encryption protocols and cipher suites                         |                                                                                                              |
   +-----------------+-----------------+----------------------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------+
