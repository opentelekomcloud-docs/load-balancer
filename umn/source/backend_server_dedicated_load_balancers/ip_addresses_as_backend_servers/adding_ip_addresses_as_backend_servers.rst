:original_name: elb_ug_hd3_0004_03.html

.. _elb_ug_hd3_0004_03:

Adding IP Addresses as Backend Servers
======================================

Scenario
--------

If you enable IP as a backend, you can associate backend servers with the load balancer by using their IP addresses.

You need to get prepared for different scenarios as shown in :ref:`Table 1 <elb_ug_hd3_0004_03__en-us_topic_0000001439818489_table417613167431>`.

.. _elb_ug_hd3_0004_03__en-us_topic_0000001439818489_table417613167431:

.. table:: **Table 1** Adding IP Addresses as Backend Servers

   +----------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
   | Where Servers Are Running                                                  | Preparations                                                                                                                                                                                                                                                      |                       |
   +============================================================================+===================================================================================================================================================================================================================================================================+=======================+
   | In a VPC that is different from the VPC where the load balancer is running | Set up a VPC peering connection between the two VPCs.                                                                                                                                                                                                             |                       |
   |                                                                            |                                                                                                                                                                                                                                                                   |                       |
   |                                                                            | For details about how to set up a VPC peering connection, see the Virtual Private Cloud User Guide.                                                                                                                                                               |                       |
   +----------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
   | In an on-premises data center                                              | Connect the on-premises data center to the VPC where the load balancer is running through Direct Connect or VPN. For details about how to connect on-premises data centers to the cloud, see the Direct Connect User Guide or Virtual Private Network User Guide. |                       |
   +----------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+

Constraints and Limitations
---------------------------

-  If IP as a backend is not enabled when you create a load balancer, you can enable it on the **Summary** page of the load balancer.
-  Only private IPv4 addresses can be added as backend servers.

-  The backend subnet of the load balancer must have sufficient IP addresses. Otherwise, backend servers cannot be added through IP addresses. If the IP addresses are insufficient, you can add more backend subnets on the **Summary** page of the load balancer.
-  Security group rules of backend servers added through IP addresses must allow traffic from the backend subnet of the load balancer. If traffic is not allowed, health checks will fail.

Procedure
---------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Click |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. In the navigation pane on the left, choose **Elastic Load Balancing** > **Backend Server Groups**.
#. On the **Backend Server Groups** page, click the name of the backend server group.
#. Switch to the **Backend Servers** tab and click **Add** in the **IP as Backend Servers** area.
#. Specify the IP addresses, ports, and weights for the backend servers.
#. Click **OK**.

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001794660485.png
