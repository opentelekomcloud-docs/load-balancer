:original_name: elb_faq_210309.html

.. _elb_faq_210309:

Can Backend Servers Access the Internet Using the EIP of the Load Balancer?
===========================================================================

No.

The load balancer uses the EIP to receive requests from the Internet and routes the requests to backend servers over a private network.

If you want the backend servers to access the Internet or provide Internet-accessible services directly, you can bind an EIP to each backend server. You can also configure a NAT gateway for the backend servers so that they can share an EIP to access the Internet.
