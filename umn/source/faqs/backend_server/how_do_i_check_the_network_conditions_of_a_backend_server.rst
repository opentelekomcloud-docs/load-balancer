How Do I Check the Network Conditions of a Backend Server?
==========================================================

#. Verify that an IP address has been assigned to the server's primary NIC.

   a. Log in to the server. (An ECS is used as an example here.)

   b. Run the **ifconfig** or **ip address** command to view the IP address.\ |image1|

      For Windows ECSs, run **ipconfig** on the CLI to view their IP addresses.

#. Ping the gateway of the subnet where the ECS resides to check basic network communication.

   a. On the VPC details page, locate the subnet and view the gateway address in the **Gateway** column. Generally, the gateway address ends with **.1**.
   b. Ping the gateway from the ECS. If the gateway cannot be pinged, check the networks at Layer 2 and Layer 3.

.. |image1| image:: /images/note_3.0-en-us.png
