:original_name: en-us_topic_0000001794819209.html

.. _en-us_topic_0000001794819209:

Slow Start (Dedicated Load Balancers)
=====================================

If you enable slow start, the load balancer linearly increases the proportion of requests to the new backend servers added to the backend server group. When the slow start duration elapses, the load balancer sends full share of requests to backend servers. For details about how to set weights for backend servers, see :ref:`Backend Server Weights <elb_ug_hd3_0001__en-us_topic_0000001384422734_section84064491587>`.

Slow start gives applications time to warm up and respond to requests with optimal performance.

.. note::

   Slow start is only available for HTTP and HTTPS backend server groups of dedicated load balancers.

Backend servers will exit slow start in either of the following cases:

-  The slow start duration elapses.
-  Backend servers become unhealthy during the slow start duration.

Constraints
-----------

-  Weighted round robin must be selected as the load balancing algorithm.
-  Slow start takes effect only for new backend servers and does not take effect when the first backend server is added to a backend server group.
-  After the slow start duration elapses, backend servers will not enter the slow start mode again.
-  Slow start takes effect when health check is enabled and the backend servers are running normally.
-  If health check is disabled, slow start takes effect immediately.
