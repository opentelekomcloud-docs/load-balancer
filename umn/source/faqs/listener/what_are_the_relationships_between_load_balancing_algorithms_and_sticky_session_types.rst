What Are the Relationships Between Load Balancing Algorithms and Sticky Session Types?
======================================================================================

Sticky sessions ensure that requests from the same client are forwarded to the same backend server. ELB supports three types of sticky sessions. `Table 3 <#en-us_elb_05_0008__table1612018518726>`__ lists the relationships between load balancing algorithms and sticky session types of classic load balancers. `Table 1 <#en-us_elb_05_0008__table44808652142126>`__ lists the relationships between load balancing algorithms and sticky session types of shared load balancers, and `Table 2 <#en-us_elb_05_0008__table169631166584>`__ lists the relationships between load balancing algorithms and sticky session types of dedicated load balancers.

|image1|

Classic load balancers can no longer be created on the management console. Use shared load balancers or dedicated load balancers instead.



.. _en-us_elb_05_0008__table44808652142126:

.. table:: **Table 1** Sticky sessions supported by shared load balancers

   ============================ ==================== ===================== ========================
   **Load Balancing Algorithm** Sticky Session Type  **Layer 4 (TCP/UDP)** **Layer 7 (HTTP/HTTPS)**
   ============================ ==================== ===================== ========================
   Weighted round robin         Source IP address    Supported             Not supported
   \                            Load balancer cookie N/A                   Supported
   \                            Application cookie   N/A                   Supported
   Weighted least connections   Source IP address    Not supported         Not supported
   \                            Load balancer cookie N/A                   Not supported
   \                            Application cookie   N/A                   Not supported
   Source IP hash               Source IP address    N/A                   Not supported
   \                            Load balancer cookie N/A                   Not supported
   \                            Application cookie   N/A                   Not supported
   ============================ ==================== ===================== ========================



.. _en-us_elb_05_0008__table169631166584:

.. table:: **Table 2** Sticky sessions supported by dedicated load balancers

   ============================ ==================== ===================== ========================
   **Load Balancing Algorithm** Sticky Session Type  **Layer 4 (TCP/UDP)** **Layer 7 (HTTP/HTTPS)**
   ============================ ==================== ===================== ========================
   Weighted round robin         Source IP address    Supported             Not supported
   \                            Load balancer cookie N/A                   Supported
   \                            Application cookie   N/A                   Not supported
   Weighted least connections   Source IP address    Not supported         Not supported
   \                            Load balancer cookie N/A                   Not supported
   \                            Application cookie   N/A                   Not supported
   Source IP hash               Source IP address    N/A                   Not supported
   \                            Load balancer cookie N/A                   Not supported
   \                            Application cookie   N/A                   Not supported
   ============================ ==================== ===================== ========================



.. _en-us_elb_05_0008__table1612018518726:

.. table:: **Table 3** Session stickiness of classic load balancers

   ============================ ======================= ===================== ========================
   **Load Balancing Algorithm** **Sticky Session Type** **Layer 4 (TCP/UDP)** **Layer 7 (HTTP/HTTPS)**
   ============================ ======================= ===================== ========================
   Round robin                  Source IP address       Supported             Not supported
   \                            Load balancer cookie    N/A                   Supported
   \                            Application cookie      N/A                   Not supported
   Least connections            Source IP address       Supported             Not supported
   \                            Load balancer cookie    N/A                   Not supported
   \                            Application cookie      N/A                   Not supported
   Source IP hash               Source IP address       N/A                   Not supported
   \                            Load balancer cookie    N/A                   Not supported
   \                            Application cookie      N/A                   Not supported
   ============================ ======================= ===================== ========================

Generally, the weighted round robin algorithm is recommended. Sticky sessions at Layer 4 use source IP addresses to main sessions, and sticky sessions at Layer 7 use load balancer cookies.

.. |image1| image:: /images/note_3.0-en-us.png
