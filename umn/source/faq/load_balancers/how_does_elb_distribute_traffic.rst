:original_name: elb_faq_0038.html

.. _elb_faq_0038:

How Does ELB Distribute Traffic?
================================

ELB uses FullNAT to forward the incoming traffic. For load balancing at Layer 4, LVS forwards the incoming traffic to backend servers directly. For load balancing at Layer 7, LVS forwards the incoming traffic to Nginx, which then forwards the traffic to backend servers.

.. note::

   In FullNAT, LVS translates source IP addresses and destination IP addresses of the clients.


.. figure:: /_static/images/en-us_image_0168438373.jpg
   :alt: **Figure 1** Load balancing at Layer 4

   **Figure 1** Load balancing at Layer 4


.. figure:: /_static/images/en-us_image_0168438378.jpg
   :alt: **Figure 2** Load balancing at Layer 7

   **Figure 2** Load balancing at Layer 7
