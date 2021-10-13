How Does ELB Distribute Traffic?
================================

ELB uses FullNAT to forward the incoming traffic. For load balancing at Layer 4, LVS forwards the incoming traffic to backend servers directly. For load balancing at Layer 7, LVS forwards the incoming traffic to Nginx, which then forwards the traffic to backend servers.

| **Figure 1** Load balancing at Layer 4
| |image1|
  **Figure 2** Load balancing at Layer 7
| |image2|

.. |image1| image:: /images/en-us_image_0168438373.jpg

.. |image2| image:: /images/en-us_image_0168438378.jpg

