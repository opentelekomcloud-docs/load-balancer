How Do I Check If Traffic Is Evenly Distributed?
================================================

#. Check whether sticky sessions are enabled. If sticky sessions are enabled and there are few clients, traffic may be unevenly distributed.
#. Check the health of backend servers, especially those whose health changes over time. If the health check result is **Unhealthy** or switches between **Healthy** and **Unhealthy**, traffic is unbalanced.
#. Check whether the **Source IP hash** algorithm is used. If the algorithm is used, requests sent from the same IP address are routed to the same backend server, resulting in unbalanced traffic.
#. Check whether applications on the backend server use keepalive to maintain TCP persistent connections. If keepalive is used, traffic may be unbalanced because the number of requests on persistent connections is different.
#. Check whether different weights are assigned to backend servers. The traffic varies according to the weights.

|image1|

Generally, in addition to the load balancing algorithm, factors that affect load balancing include connection type, session stickiness, and server weights.

.. |image1| image:: /images/note_3.0-en-us.png
