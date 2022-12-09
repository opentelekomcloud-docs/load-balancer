:original_name: elb_faq_0039.html

.. _elb_faq_0039:

How Do I Check the Network Conditions of a Backend Server?
==========================================================

#. Verify that an IP address has been assigned to the server's primary NIC.

   a. Log in to the server. (An ECS is used as an example here.)
   b. Use **ifconfig** or **ip address** to view the IP address.

      .. note::

         For Windows ECSs, use **ipconfig** on the CLI.

#. Ping the gateway of the subnet where the ECS resides to check for network connectivity.

   a. On the VPC details page, locate the subnet and view the gateway address in the **Gateway** column. Generally, the gateway address ends with **.1**.
   b. Ping the gateway from the ECS. If the gateway cannot be pinged, check the networks at Layer 2 and Layer 3.
