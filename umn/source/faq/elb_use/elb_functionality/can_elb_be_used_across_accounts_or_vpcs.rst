:original_name: elb_faq_0135.html

.. _elb_faq_0135:

Can ELB Be Used Across Accounts or VPCs?
========================================

-  Your Shared load balancers cannot be used by another account, and you cannot associate backend servers whose VPCs are not the same as the load balancers.
-  For Dedicated load balancers, you can add servers in a VPC connected using a VPC peering connection, in a VPC in another region and connected through a cloud connection, or in an on-premises data center at the other end of a Direct Connect or VPN connection, by using their IP addresses. For details, see :ref:`Configuring Hybrid Load Balancing <elb_ug_hd_0005>`.
