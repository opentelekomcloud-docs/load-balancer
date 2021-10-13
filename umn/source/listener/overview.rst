Overview
========

You need to add at least one listener after you have created a load balancer. This listener receives requests from clients and routes requests to backend servers using the protocol, port, and load balancing algorithm you select.

Supported Protocols
-------------------

ELB provides load balancing at both Layer 4 and Layer 7.

Select TCP or UDP for load balancing at Layer 4 and HTTP or HTTPS at Layer 7.



.. _elb_ug_jt_0001__table66244785114429:

.. table:: **Table 1** Protocols supported by ELB

   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | **Protocol**                |                             | **Description**             | **Application Scenario**    |
   +=============================+=============================+=============================+=============================+
   | Layer 4                     | TCP                         | -  Source IP address-based  | -  Scenarios that require   |
   |                             |                             |    sticky sessions          |    high reliability and     |
   |                             |                             | -  Fast data transfer       |    data accuracy, such as   |
   |                             |                             |                             |    file transfer, email,    |
   |                             |                             |                             |    and remote login         |
   |                             |                             |                             | -  Web applications that    |
   |                             |                             |                             |    receive a large number   |
   |                             |                             |                             |    of concurrent requests   |
   |                             |                             |                             |    and require high         |
   |                             |                             |                             |    performance              |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Layer 4                     | UDP                         | -  Low reliability          | Scenarios that require      |
   |                             |                             | -  Fast data transfer       | quick response, such as     |
   |                             |                             |                             | video chat, gaming, and     |
   |                             |                             |                             | real-time financial         |
   |                             |                             |                             | quotations                  |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Layer 4                     | SSL                         | -  TCP-based security       | Web applications that       |
   |                             |                             |    encryption               | require encrypted           |
   |                             |                             | -  High reliability         | transmission                |
   |                             |                             | -  Supported by only        |                             |
   |                             |                             |    classic load balancers   |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Layer 7                     | HTTP                        | -  Cookie-based sticky      | Web applications where data |
   |                             |                             |    sessions                 | content needs to be         |
   |                             |                             | -  X-Forward-For request    | identified, such as mobile  |
   |                             |                             |    header                   | games                       |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Layer 7                     | HTTPS                       | -  An extension of HTTP for | Web applications that       |
   |                             |                             |    encrypted data           | require encrypted           |
   |                             |                             |    transmission to prevent  | transmission                |
   |                             |                             |    unauthorized access      |                             |
   |                             |                             | -  Encryption and           |                             |
   |                             |                             |    decryption performed on  |                             |
   |                             |                             |    load balancers           |                             |
   |                             |                             | -  Multiple versions of     |                             |
   |                             |                             |    encryption protocols and |                             |
   |                             |                             |    cipher suites            |                             |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
