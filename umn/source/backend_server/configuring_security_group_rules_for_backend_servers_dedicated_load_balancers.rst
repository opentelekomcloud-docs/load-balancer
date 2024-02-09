:original_name: elb_ug_hd_0007.html

.. _elb_ug_hd_0007:

Configuring Security Group Rules for Backend Servers (Dedicated Load Balancers)
===============================================================================

Scenarios
---------

When you add a backend server to a backend server group, ensure that the rules of the security group that containing the backend server allows access from the VPC where the backend server resides, and that the destination port is that used by the backend server. You also need to configure the protocol and port used for health checks. If you use UDP for health checks, configure inbound rules to allow ICMP traffic. Otherwise, health checks cannot be performed on the added backend server.

If you have no VPCs when creating a server, the system will automatically create a VPC with default security rules. Default security group rules allow only communications among the servers in the VPC. You also need to configure inbound rules to enable the load balancer to communicate with these servers over the frontend port and health check port.

.. note::

   If the load balancer has a TCP or UDP listener and IP as a backend is disabled, security group rules and firewall rules will not take effect. To control traffic to backend servers, you can use access control to limit which IP addresses are allowed to access the listener. Learn how to configure :ref:`access control <en-us_elb_03_0003>`.

Procedure
---------

#. Log in to the management console.

#. In the upper left corner of the page, click |image1| and select the desired region and project.

#. Hover on |image2| in the upper left corner to display **Service List** and choose **Computing** > **Elastic Cloud Server**.

#. In the ECS list, locate the ECS and click its name.

   The ECS details page is displayed.

#. Click **Security Groups**, locate the security group, and view security group rules.

#. Click the security group rule ID or **Modify Security Group Rule**. The security group details page is displayed.

#. On the **Inbound Rules** tab page, click **Add Rule**. Configure an inbound rule based on :ref:`Table 1 <elb_ug_hd_0007__en-us_topic_0000001420502298_en-us_topic_0000001390784280_table22703095416>`.

   .. _elb_ug_hd_0007__en-us_topic_0000001420502298_en-us_topic_0000001390784280_table22703095416:

   .. table:: **Table 1** Security group rules

      +------------------+-----------------+---------------------------------------------------------------------+-------------------------------------+
      | Backend Protocol | Policy          | Protocol & Port                                                     | Source IP Address                   |
      +==================+=================+=====================================================================+=====================================+
      | HTTP or HTTPS    | Allow           | **Protocol**: TCP                                                   | Backend subnet of the load balancer |
      |                  |                 |                                                                     |                                     |
      |                  |                 | **Port**: the port used by the backend server and health check port |                                     |
      +------------------+-----------------+---------------------------------------------------------------------+-------------------------------------+
      | TCP              | Allow           | **Protocol**: TCP                                                   |                                     |
      |                  |                 |                                                                     |                                     |
      |                  |                 | **Port**: health check port                                         |                                     |
      +------------------+-----------------+---------------------------------------------------------------------+-------------------------------------+
      | UDP              | Allow           | **Protocol**: UDP and ICMP                                          |                                     |
      |                  |                 |                                                                     |                                     |
      |                  |                 | **Port**: health check port                                         |                                     |
      +------------------+-----------------+---------------------------------------------------------------------+-------------------------------------+

   .. note::

      -  After a load balancer is created, do not change the subnet. If the subnet is changed, the IP addresses occupied by the load balancer will not be released, and traffic from the previous backend subnet is still need to be allowed to backend servers.
      -  Traffic from the new backend subnet is also need to be allowed to backend servers.

#. Click **OK**.

Configuring Firewall Rules
--------------------------

To control traffic in and out of a subnet, you can associate a firewall with the subnet. Firewall rules control access to subnets and add an additional layer of defense to your subnets. Default firewall rules reject all inbound and outbound traffic. If the subnet of a load balancer or associated backend servers has a firewall associated, the load balancer cannot receive traffic from the Internet or route traffic to backend servers, and backend servers cannot receive traffic from and respond to the load balancer.

Configure an inbound firewall rule to allow traffic from the VPC where the load balancer works to backend servers.

#. Log in to the management console.
#. In the upper left corner of the page, click |image3| and select the desired region and project.
#. Click |image4| in the upper left corner of the page and choose **Network** > **Virtual Private Cloud**.
#. In the navigation pane on the left, choose **Access Control** > **Firewall**.
#. In the firewall list, click the name of the firewall to switch to the page showing its details.
#. On the **Inbound Rules** or **Outbound Rules** tab page, click **Add Rule** to add a rule.

   -  **Action**: Select **Allow**.
   -  **Protocol**: The protocol must be the same as the one you selected for the listener.
   -  **Source**: Set it to the VPC CIDR block.
   -  **Source Port Range**: Select a port range.
   -  **Destination**: If you keep the default value, **0.0.0.0/0**, traffic will be allowed for all destination IP addresses.
   -  **Destination Port Range**: Select a port range.
   -  (Optional) **Description**: Describe the firewall rule.

#. Click **OK**.

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001794820117.png
.. |image3| image:: /_static/images/en-us_image_0000001747739624.png
.. |image4| image:: /_static/images/en-us_image_0000001747739880.png
