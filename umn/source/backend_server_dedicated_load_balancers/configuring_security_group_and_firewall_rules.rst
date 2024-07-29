:original_name: elb_ug_hd_0007.html

.. _elb_ug_hd_0007:

Configuring Security Group and Firewall Rules
=============================================

Scenarios
---------

To ensure normal communications between the load balancer and backend servers, you need to check the security group rules and firewall rules configured for the backend servers.

-  Security group rules must allow traffic from the backend subnet where the load balancer resides to the backend servers. (By default, the backend subnet of a load balancer is the same as the subnet where the load balancer resides.) For details about how to configure security group rules, see :ref:`Configuring Security Group Rules <elb_ug_hd_0007__en-us_topic_0000001390784280_section20777195619242>`.

-  Firewall rules are optional for subnets. If firewall rules are configured for the backend subnet of the load balancer, the firewall rules must allow traffic from the backend subnet of the load balancer to the backend servers. For details about how to configure rules, see :ref:`Configuring Firewall Rules <elb_ug_hd_0007__en-us_topic_0000001390784280_section1261104918577>`.

.. note::

   If the load balancer has Layer 4 listeners and **IP as a Backend** is disabled, firewall rules and security group rules will not take effect.

   You can use access control to limit which IP addresses are allowed to access the listener. Learn how to configure :ref:`Access Control <elb_03_0003>`.

Constraints and Limitations
---------------------------

-  If health check is enabled for a backend server group, security group rules must allow traffic from the health check port over the health check protocol.
-  If UDP is used for health check, there must be a rule that allows ICMP traffic to check the health of the backend servers.

.. _elb_ug_hd_0007__en-us_topic_0000001390784280_section20777195619242:

Configuring Security Group Rules
--------------------------------

If you have no VPCs when creating a server, a default VPC will be created for you. Default security group rules allow only communications among the servers in the VPC. To ensure that the load balancer can communicate with these servers over both the frontend port and health check port, configure inbound rules for security groups containing these servers.

#. Log in to the management console.

#. In the upper left corner of the page, click |image1| and select the desired region and project.

#. Click |image2| in the upper left corner to display **Service List** and choose **Computing** > **Elastic Cloud Server**.

#. In the ECS list, click the name of the ECS whose security group rules you want to modify.

   The page providing details about the ECS is displayed.

#. Click **Security Groups**, locate the security group, and view security group rules.

#. Click the ID of a security group rule or **Modify Security Group Rule**. The security group details page is displayed.

#. On the **Inbound Rules** tab page, click **Add Rule**. Configure an inbound rule based on :ref:`Table 1 <elb_ug_hd_0007__en-us_topic_0000001390784280_table22703095416>`.

   .. _elb_ug_hd_0007__en-us_topic_0000001390784280_table22703095416:

   .. table:: **Table 1** Security group rules

      +------------------+-----------------+-------------------------------------------------------------------------+-------------------------------------+
      | Backend Protocol | Policy          | Protocol & Port                                                         | Source IP Address                   |
      +==================+=================+=========================================================================+=====================================+
      | HTTP or HTTPS    | Allow           | **Protocol**: TCP                                                       | Backend subnet of the load balancer |
      |                  |                 |                                                                         |                                     |
      |                  |                 | **Port**: the port used by the backend server and the health check port |                                     |
      +------------------+-----------------+-------------------------------------------------------------------------+-------------------------------------+
      | TCP              | Allow           | **Protocol**: TCP                                                       | Backend subnet of the load balancer |
      |                  |                 |                                                                         |                                     |
      |                  |                 | **Port**: health check port                                             |                                     |
      +------------------+-----------------+-------------------------------------------------------------------------+-------------------------------------+
      | UDP              | Allow           | **Protocol**: UDP and ICMP                                              | Backend subnet of the load balancer |
      |                  |                 |                                                                         |                                     |
      |                  |                 | **Port**: health check port                                             |                                     |
      +------------------+-----------------+-------------------------------------------------------------------------+-------------------------------------+

   .. note::

      -  After a load balancer is created, do not change the subnet. If the subnet is changed, the IP addresses occupied by the load balancer will not be released, and traffic from the previous backend subnet is still need to be allowed to backend servers.
      -  Traffic from the new backend subnet is also need to be allowed to backend servers.

#. Click **OK**.

.. _elb_ug_hd_0007__en-us_topic_0000001390784280_section1261104918577:

Configuring Firewall Rules
--------------------------

To control traffic in and out of a subnet, you can associate a firewall with the subnet. Firewall rules control access to subnets and add an additional layer of defense to your subnets.

The default firewall rule denies all inbound and outbound traffic. You can configure an inbound rule to allow traffic from the backend subnet of the load balancer through the port of the backend server.

#. Log in to the management console.
#. In the upper left corner of the page, click |image3| and select the desired region and project.
#. Click |image4| in the upper left corner to display **Service List** and choose **Network** > **Virtual Private Cloud**.
#. In the navigation pane on the left, choose **Access Control** > **Firewalls**.
#. In the firewall list, click the name of the firewall to switch to the page showing its details.
#. On the **Inbound Rules** or **Outbound Rules** tab page, click **Add Rule** to add an inbound or outbound rule.

   -  **Type**: Select the IP address type supported by the rule. The value can be **IPv4** or **IPv6**.
   -  **Action**: Select **Allow**.
   -  **Protocol**: The protocol must be the same as the backend protocol.
   -  **Source**: Set it to the backend subnet of the load balancer.
   -  **Source Port Range**: Select a port range based on the service requirements.
   -  **Destination**: Enter a destination address allowed in this direction. The default value is **0.0.0.0/0**, which indicates that traffic from all IP addresses is permitted.
   -  **Destination Port Range**: Select a port range based on the service requirements.
   -  (Optional) **Description**: Describe the firewall rule if necessary.

#. Click **OK**.

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001470654829.png
.. |image3| image:: /_static/images/en-us_image_0000001747739624.png
.. |image4| image:: /_static/images/en-us_image_0000001747381344.png
