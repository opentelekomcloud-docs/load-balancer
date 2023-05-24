:original_name: elb_faq_0049.html

.. _elb_faq_0049:

How Do I Check for Traffic Inconsistencies?
===========================================

Check for failed requests on the clients, especially when *4xx* status codes are returned. One possible cause is that the requests are not being routed to backend servers because ELB considers these requests abnormal.
