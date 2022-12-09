:original_name: elb_faq_0040.html

.. _elb_faq_0040:

How Do I Check the Network Configuration of a Backend Server?
=============================================================

#. Check whether the security group of the server is correctly configured.

   a. On the server details page, view the security group.
   b. Check whether the security group rules allow access from the corresponding IP address range.

      -  Dedicated load balancers: Check whether the security group containing the backend server has inbound rules to allow traffic from the VPC where the load balancer works. If traffic is not allowed, add an inbound rule to allow traffic from the VPC to the backend server.
      -  Shared load balancers: Check whether the security group containing the backend server has inbound rules to allow traffic from the 100.125.0.0/16. If traffic is not allowed, add an inbound rule to allow traffic from 100.125.0.0/16 to the backend server.

      .. caution::

         -  Shared load balancers: If **Obtain Client IP Address** is enabled for a TCP or UDP listener, there is no need to configure security group rules and firewall rules to allow traffic from 100.125.0.0/16 and client IP addresses to backend servers.

#. Ensure that the network ACLfirewalls of the subnet where the server resides does not intercept the traffic.

   In the navigation pane of the VPC console, choose **Access Control** > **Firewalls** and check whether the subnet allows traffic.
