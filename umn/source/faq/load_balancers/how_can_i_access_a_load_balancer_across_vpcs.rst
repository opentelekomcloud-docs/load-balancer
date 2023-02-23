:original_name: elb_faq_0080.html

.. _elb_faq_0080:

How Can I Access a Load Balancer Across VPCs?
=============================================

VPC Peering can help you achieve this. For example, if another user has created load balancer ELB01 in VPC01, and you are in VPC02 and want to access ELB01, you just need to set up a VPC peering connection between VPC01 and VPC02 and add a route for the connection.
