:original_name: elb_faq_0112.html

.. _elb_faq_0112:

Why Is the Interval at Which Backend Servers Receive Health Check Packets Different from What I Have Configured?
================================================================================================================

Each LVS node and Nginx node in the ELB system send detection packets to backend servers at the health check interval that you have specified for the backend server group.

During this period, backend servers receive multiple detection packets from LVS and Nginx nodes. This makes it seem like backend servers are receiving packets at intervals shorter than the specified health check interval.
