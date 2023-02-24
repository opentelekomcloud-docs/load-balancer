:original_name: elb_faq_0040.html

.. _elb_faq_0040:

How Can I Check the Network Configuration of a Backend Server?
==============================================================

#. Check whether the security group of the server is correctly configured.

   a. On the server details page, view the security group.
   b. Check whether the security group rules allow access from the corresponding IP address range.

      -  Dedicated load balancers: Check whether the security group of the backend server has inbound rules to allow traffic from the VPC where the load balancer works. If traffic is not allowed, add an inbound rule to allow traffic from the VPC to the backend server.
      -  Shared load balancers: Check whether the security group of the backend server has inbound rules to allow traffic from the 100.125.0.0/16. If traffic is not allowed, add an inbound rule to allow traffic from 100.125.0.0/16 to the backend server.

      .. caution::

         -  Shared load balancers: If **Transfer Client IP Address** is enabled for a TCP or UDP listener, there is no need to configure security group rules and firewall rules to allow traffic from 100.125.0.0/16 and client IP addresses to backend servers.
         -  Dedicated load balancer: If **IP as a Backend** is not enabled for a load balancer that has a TCP or UDP listener, there is no need to configure security group rules and firewall rules to allow traffic from the VPC where the load balancer works to the backend servers associated with TCP or UDP listener.

#. Ensure that the firewalls of the subnet where the server resides does not intercept the traffic.

   In the navigation pane of the VPC console, choose **Access Control** > **Firewalls** and check whether the subnet allows traffic.
