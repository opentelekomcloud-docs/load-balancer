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

-  Backend servers must be in the same VPC as the load balancer.
-  For ease of management and maintenance, backend servers must run the same OS.
-  You can set a weight for each server in the backend server group. The larger the weight is, the higher proportion of requests the backend server receives.
-  If you enable sticky sessions, the proportions of requests processed by backend servers may become unbalanced. In this case, disable sticky sessions and check the requests received by each backend server.
