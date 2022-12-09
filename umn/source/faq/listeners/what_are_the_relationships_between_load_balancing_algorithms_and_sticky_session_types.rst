:original_name: en-us_elb_05_0008.html

.. _en-us_elb_05_0008:

What Are the Relationships Between Load Balancing Algorithms and Sticky Session Types?
======================================================================================

ELB supports three types of sticky sessions that can send requests from the same client to the same backend server. The following tables list the types of sticky sessions corresponding to each load balancing algorithm.

.. _en-us_elb_05_0008__table169631166584:

.. table:: **Table 1** Sticky sessions supported by dedicated load balancers

   +----------------------------+----------------------+-------------------+----------------------+
   | Load Balancing Algorithm   | Sticky Session Type  | Layer 4 (TCP/UDP) | Layer 7 (HTTP/HTTPS) |
   +============================+======================+===================+======================+
   | Weighted round robin       | Source IP address    | Supported         | Not supported        |
   +----------------------------+----------------------+-------------------+----------------------+
   |                            | Load balancer cookie | N/A               | Supported            |
   +----------------------------+----------------------+-------------------+----------------------+
   |                            | Application cookie   | N/A               | Not supported        |
   +----------------------------+----------------------+-------------------+----------------------+
   | Weighted least connections | Source IP address    | Not supported     | Not supported        |
   +----------------------------+----------------------+-------------------+----------------------+
   |                            | Load balancer cookie | N/A               | Not supported        |
   +----------------------------+----------------------+-------------------+----------------------+
   |                            | Application cookie   | N/A               | Not supported        |
   +----------------------------+----------------------+-------------------+----------------------+
   | Source IP hash             | Source IP address    | N/A               | Not supported        |
   +----------------------------+----------------------+-------------------+----------------------+
   |                            | Load balancer cookie | N/A               | Not supported        |
   +----------------------------+----------------------+-------------------+----------------------+
   |                            | Application cookie   | N/A               | Not supported        |
   +----------------------------+----------------------+-------------------+----------------------+

.. table:: **Table 2** Sticky sessions supported by shared load balancers

   +----------------------------+----------------------+-------------------+----------------------+
   | Load Balancing Algorithm   | Sticky Session Type  | Layer 4 (TCP/UDP) | Layer 7 (HTTP/HTTPS) |
   +============================+======================+===================+======================+
   | Weighted round robin       | Source IP address    | Supported         | Not supported        |
   +----------------------------+----------------------+-------------------+----------------------+
   |                            | Load balancer cookie | N/A               | Supported            |
   +----------------------------+----------------------+-------------------+----------------------+
   |                            | Application cookie   | N/A               | Supported            |
   +----------------------------+----------------------+-------------------+----------------------+
   | Weighted least connections | Source IP address    | Not supported     | Not supported        |
   +----------------------------+----------------------+-------------------+----------------------+
   |                            | Load balancer cookie | N/A               | Not supported        |
   +----------------------------+----------------------+-------------------+----------------------+
   |                            | Application cookie   | N/A               | Not supported        |
   +----------------------------+----------------------+-------------------+----------------------+
   | Source IP hash             | Source IP address    | N/A               | Not supported        |
   +----------------------------+----------------------+-------------------+----------------------+
   |                            | Load balancer cookie | N/A               | Not supported        |
   +----------------------------+----------------------+-------------------+----------------------+
   |                            | Application cookie   | N/A               | Not supported        |
   +----------------------------+----------------------+-------------------+----------------------+

Generally, the weighted round robin algorithm is recommended. Sticky sessions at Layer 4 use source IP addresses to main sessions, and sticky sessions at Layer 7 use load balancer cookies.
