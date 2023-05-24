:original_name: elb_ug_hd_0001.html

.. _elb_ug_hd_0001:

Overview
========

A backend server is a cloud server added to a backend server group associated with a load balancer. When you add a listener to a load balancer, you can create or select a backend server group to receive requests from the load balancer by using the port and protocol you specify for the backend server group and the load balancing algorithm you select.

After a new server is added to the associated backend server group for which the health check is configured, the load balancer will check its running status. If the backend server responds normally, it is declared healthy. If the backend server does not respond normally, the load balancer periodically checks its health for multiple times. Only after the backend server is considered healthy, it can receive requests from the load balancer.

You can adjust the number of backend servers to ensure stable and reliable service with the minimum budget. Load balancers can distribute requests across backend servers in different AZs to prevent SPOFs. You must ensure that at least one backend server is working normally in each AZ.

On the ELB console, you can view the load balancer that the backend server is associated with by the IP address or ID of the backend server.

If a backend server is stopped or restarted, connections established with the server will be disconnected, and data being transmitted over these connections will be lost. Configure the retry function on the clients to prevent data loss.

Notes
-----

When you add backend servers, note the following:

-  Backend servers must be in the same VPC as the load balancer if IP as a backend is not enabled.
-  For ease of management and maintenance, backend servers must run the same OS.
-  You can set a weight for each server in the backend server group. The larger the weight is, the higher proportion of requests the backend server receives.
-  If you enable sticky sessions, the proportions of requests processed by backend servers may become unbalanced. In this case, disable sticky sessions and check the requests received by each backend server.

Slow Start
----------

After you enable slow start, the load balancer linearly increases the proportion of requests to send to backend servers in this mode. When the slow start duration elapses, the load balancer sends full share of requests to backend servers and exits the slow start mode.

When you enable slow start, note the following:

-  Slow start can only be enabled for HTTP and HTTPS backend server groups.
-  If slow start is enabled, only the weighted round robin algorithm can be used.
-  Slow start can be enabled only for new backend servers. If a backend server group has no backend servers, slow start will not take effect for the first backend server added to the backend server group.
-  When the health check function is enabled, slow start takes effect after backend servers are detected healthy. The slow start duration will not stop even if the health check is abnormal due to network exceptions or other reasons.
-  When the health check function is disabled, slow start takes effect immediately.
-  After the slow start duration elapses, backend servers will not enter the slow start mode again.

.. note::

   The slow start function applies only to dedicated load balancers.

IP as Backend Servers
---------------------

If you enable IP as a backend, you can add backend servers that are not in the VPC of the load balancer, using their private IP addresses. The backend servers can be in a VPC connected through a VPC peering connection, or in an on-premises data center at the other end of a Direct Connect or VPN connection.

When you add IP as backend servers, note the following:

-  If you do not enable the function when you create a load balancer, you can still enable it on the **Summary** page of the load balancer.
-  IP as backend servers must use IPv4 addresses.
-  Configure the VPC routes correctly to ensure that backend servers are reachable. For details, see :ref:`Adding or Removing Backend Servers (Dedicated Load Balancers) <elb_ug_hd_0003>`.
-  If you enable IP as a backend for a load balancer, you can add only TCP, HTTP, and HTTPS listeners to the load balancer.
-  The subnet where the load balancer works must have sufficient IP addresses (at least 16 IP addresses). You can add more subnets for more IP addresses on the **Summary** page of the load balancer.
-  Security group rules of IP as backend servers must allow traffic from the subnet of the load balancer. Otherwise, health checks will fail.
-  IP as backend cannot be disabled after it is enabled.
-  A maximum of 492 servers can be associated with a load balancer.
-  Source IP addresses of the clients cannot be passed to IP as backend servers.

.. note::

   The IP as a backend function applies only to dedicated load balancers.
