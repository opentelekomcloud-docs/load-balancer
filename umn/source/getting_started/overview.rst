Overview
========

Two examples are given to show how you can quickly create a shared load balancer to distribute incoming traffic across backend servers.

-  **Entry level**: A large number of requests need to be routed to backend servers. Health checks are required to monitor the health of backend servers to ensure that incoming traffic is routed only to healthy backend servers to eliminate SPOFs and improve service availability.\ **Figure 1** Entry level
   |image1|

   As the incoming traffic increases, you can add more servers to balance the load across backend servers.

-  **Advanced level**: Two or more applications use the domain name to provide services, and requests are routed to applications based on their URLs. Forwarding policies are required to forward requests from different URLs to the corresponding backend server groups.\ **Figure 2** Advanced level
   |image2|

   As the incoming traffic increases, you can add more backend servers to the two backend server groups. You can also configure health checks to monitor the health of backend servers to ensure that incoming traffic is routed only to healthy backend servers.

.. |image1| image:: /images/en-us_image_0198607819.png
   :class: vsd

.. |image2| image:: /images/en-us_image_0198607873.png
   :class: vsd

