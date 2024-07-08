:original_name: elb_faq_0135.html

.. _elb_faq_0135:

Can ELB Be Used Across Accounts or VPCs?
========================================

-  Shared load balancers cannot be used across accounts and cannot route traffic to backend servers in VPCs that are different from the VPCs of the load balancers.
-  For dedicated load balancers, you can add servers in a VPC connected using a VPC peering connection, in a VPC in another region and connected through a cloud connection, or in an on-premises data center at the other end of a Direct Connect or VPN connection, by using their IP addresses. For details, see :ref:`Overview <elb_ug_hd3_0004_01>`.
