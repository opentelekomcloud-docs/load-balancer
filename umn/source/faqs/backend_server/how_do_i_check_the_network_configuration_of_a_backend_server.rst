How Do I Check the Network Configuration of a Backend Server?
=============================================================

#. Check whether the security group of the server is correctly configured.

   a. On the server details page, view the security group.
   b. Check whether the security group allows access from IP addresses in 100.125.0.0/16. If access is not allowed, add inbound rules for 100.125.0.0/16.

#. Ensure that the network ACLs of the subnet where the server resides does not intercept the traffic.

   In the left navigation pane on the VPC console, choose **Access Control**> **Network ACLs** and check whether the subnet allows traffic.
