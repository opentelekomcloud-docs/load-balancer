:original_name: elb_faq_0001.html

.. _elb_faq_0001:

When Is a Backend Server Considered Healthy?
============================================

When a backend server is associated with a load balancer for the first time, the backend server is considered healthy after one health check. After this, the server is considered healthy only after the maximum number of health checks has been attempted.
