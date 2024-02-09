:original_name: elb_ug_hd_0002.html

.. _elb_ug_hd_0002:

Configuring Security Group Rules for Backend Servers (Shared Load Balancers)
============================================================================

Scenarios
---------

Before you add servers to a backend server group, ensure that their security groups have inbound rules that allow traffic from 100.125.0.0/16, and specify the health check protocol and port. Otherwise, health checks will be affected, and backend servers cannot receive requests from the load balancer. If UDP is used for health checks, inbound security group rules must also allow the ICMP traffic.

If you have no VPCs when creating a server, the system will automatically create a VPC with default security rules. Default security group rules allow only communications among the servers in the VPC. You also need to configure inbound rules to enable the load balancer to communicate with these servers over the frontend port and health check port.

.. note::

   If **Transfer Client IP Address** is enabled for the TCP or UDP listeners, firewall rules and security group rules will not take effect. To control traffic to backend servers, you can use access control to limit which IP addresses are allowed to access the listener. Learn how to configure :ref:`access control <en-us_elb_03_0003>`.

Procedure
---------

#. Log in to the management console.

#. In the upper left corner of the page, click |image1| and select the desired region and project.

#. Hover on |image2| in the upper left corner to display **Service List** and choose **Computing** > **Elastic Cloud Server**.

#. In the ECS list, locate the ECS and click its name.

   The ECS details page is displayed.

#. Click **Security Groups**, locate the security group, and view security group rules.

#. Click the security group rule ID or **Modify Security Group Rule**.

   The security group details page is displayed.

#. On the **Inbound Rules** tab page, click **Add Rule**. Configure an inbound rule based on :ref:`Table 1 <elb_ug_hd_0002__en-us_topic_0000001434422737_table22703095416>`.

   .. _elb_ug_hd_0002__en-us_topic_0000001434422737_table22703095416:

   .. table:: **Table 1** Security group rules

      +------------------+-----------------+---------------------------------------------------------------------+-------------------+
      | Backend Protocol | Policy          | Protocol & Port                                                     | Source IP Address |
      +==================+=================+=====================================================================+===================+
      | HTTP             | Allow           | **Protocol**: TCP                                                   | 100.125.0.0/16    |
      |                  |                 |                                                                     |                   |
      |                  |                 | **Port**: the port used by the backend server and health check port |                   |
      +------------------+-----------------+---------------------------------------------------------------------+-------------------+
      | TCP              | Allow           | **Protocol**: TCP                                                   | 100.125.0.0/16    |
      |                  |                 |                                                                     |                   |
      |                  |                 | **Port**: health check port                                         |                   |
      +------------------+-----------------+---------------------------------------------------------------------+-------------------+
      | UDP              | Allow           | **Protocol**: UDP and ICMP                                          | 100.125.0.0/16    |
      |                  |                 |                                                                     |                   |
      |                  |                 | **Port**: health check port                                         |                   |
      +------------------+-----------------+---------------------------------------------------------------------+-------------------+

#. Click **OK**.

Configuring Firewall Rules
--------------------------

To control traffic in and out of a subnet, you can associate a firewall with the subnet. Firewall rules control access to subnets and add an additional layer of defense to your subnets. Default firewall rules reject all inbound and outbound traffic. If the subnet of a load balancer or associated backend servers has a firewall associated, the load balancer cannot receive traffic from the Internet or route traffic to backend servers, and backend servers cannot receive traffic from and respond to the load balancer.

Configure an inbound firewall rule to permit access from 100.125.0.0/16.

ELB translates public IP addresses that access backend servers into IP addresses in 100.125.0.0/16. You cannot configure firewall rules to prevent public IP addresses from accessing backend servers to allow traffic from 100.125.0.0/16 to all backend servers.

#. Log in to the management console.
#. In the upper left corner of the page, click |image3| and select the desired region and project.
#. Click |image4| in the upper left corner of the page and choose **Network** > **Virtual Private Cloud**.
#. In the navigation pane on the left, choose **Access Control** > **Firewall**.
#. In the firewall list, click the name of the firewall to switch to the page showing its details.
#. On the **Inbound Rules** or **Outbound Rules** tab page, click **Add Rule** to add a rule.

   -  **Action**: Select **Allow**.
   -  **Protocol**: The protocol must be the same as the one you selected for the listener.
   -  **Source**: Set it to **100.125.0.0/16**.
   -  **Source Port Range**: Select a port range.
   -  **Destination**: If you keep the default value, **0.0.0.0/0**, traffic will be allowed for all destination IP addresses.
   -  **Destination Port Range**: Select a port range.
   -  (Optional) **Description**: Describe the firewall rule.

#. Click **OK**.

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001794820117.png
.. |image3| image:: /_static/images/en-us_image_0000001747739624.png
.. |image4| image:: /_static/images/en-us_image_0000001794819601.png
