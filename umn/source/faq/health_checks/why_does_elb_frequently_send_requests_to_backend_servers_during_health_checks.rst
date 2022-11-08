:original_name: elb_faq_0114.html

.. _elb_faq_0114:

Why Does ELB Frequently Send Requests to Backend Servers During Health Checks?
==============================================================================

ELB is deployed in clusters, and all nodes for request forwarding in the cluster send requests to backend servers at the same time. If the health check interval is too short, health checks are performed once every few seconds, and a large number of packets are sent to backend servers. To control the frequency of access to backend servers, change the health check interval by referring to :ref:`Configuring a Health Check <en-us_topic_0162227063>`.
