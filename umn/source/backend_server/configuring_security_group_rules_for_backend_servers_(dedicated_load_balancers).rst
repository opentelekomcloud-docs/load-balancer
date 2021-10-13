Configuring Security Group Rules for Backend Servers (Dedicated Load Balancers)
===============================================================================

Scenarios
---------

When you add a backend server to a backend server group, ensure that the rules of the security group that containing the backend server allows access from the CIDR block of the VPC where the backend server resides, and that the destination port is that used by the backend server. You also need to configure the protocol and port used for health checks. If you use UDP for health checks, configure inbound rules to allow ICMP traffic. Otherwise, health checks cannot be performed on the added backend server.

If you have no VPCs when creating a server, the system will automatically create a VPC with default security rules. Default security group rules allow only communications among the servers in the VPC. You also need to configure inbound rules to enable the load balancer to communicate with these servers over the frontend port and health check port.

Procedure
---------

#. Log in to the management console.

#. In the upper left corner of the page, click |image1| and select the desired region and project.

#. Hover on |image2| in the upper left corner to display **Service List** and choose **Computing** > **Elastic Cloud Server**.

#. In the ECS list, locate the ECS and click its name.

   The ECS details page is displayed.

#. Click **Security Groups**, locate the security group, and view security group rules.

#. Click the security group rule ID or **Modify Security Group Rule**. The security group details page is displayed.

#. Under **Inbound Rules**, click **Add Rule**.

   **TCP, HTTP, or HTTPS listeners**

   -  If the health check port is not the one used by each backend server, add an inbound rule to allow TCP traffic over the health check port and the ports used by backend servers.
   -  If you do not specify a health check port, add inbound rules to allow TCP traffic over the ports used by backend servers.
   -  To ensure normal health checks, ensure that security group rules allow traffic from the CIDR block of the subnet where the load balancer resides and traffic from the health check port and from the ports used by backend servers.

   **UDP listeners**

   -  If the health check port is not the one used by each backend server, add an inbound rule to allow UDP traffic over the health check port and the ports used by backend servers.
   -  If you do not specify a health check port, add inbound rules to allow UDP traffic over the ports used by backend servers.
   -  To ensure normal health checks, ensure that security group rules allow traffic from the CIDR block of the subnet where the load balancer resides and traffic from the health check port and from the ports used by backend servers.
   -  You need also to add an inbound rule to allow ICMP traffic.

#. Click **OK**.

Firewall Rule
-------------

You can associate one or more subnets with a firewall for controlling traffic in and out of the subnets. Similar to security groups, firewalls provide access control functions, but add an additional layer of defense to your VPC. Default firewall rules reject all inbound and outbound traffic. If the subnet of a load balancer or associated backend servers has a firewall associated, the load balancer cannot receive traffic from the Internet or route traffic to backend servers, and backend servers cannot receive traffic from and respond to the load balancer.

Configure an inbound firewall rule to allow access from the VPC CIDR block to backend servers.

#. Log in to the management console.
#. In the upper left corner of the page, click |image3| and select the desired region and project.
#. Hover on |image4| in the upper left corner to display **Service List** and choose **Network** > **Virtual Private Cloud**.
#. In the navigation pane on the left, choose **Access Control** > **Firewalls**.
#. Locate the firewall, and click the firewall name to switch to the firewall details page.
#. On the **Inbound Rules** or **Outbound Rules** tab page, click **Add Rule** to add a rule.

   -  **Action**: Select **Allow**.
   -  **Protocol**: The protocol must be the same as the frontend protocol you select when you add the listener.
   -  **Source**: Set the value to the VPC CIDR block.
   -  **Source Port Range**: Select the port range.
   -  **Destination**: Enter the default value **0.0.0.0/0**. Traffic will be destined for all IP addresses.
   -  **Destination Port Range**: Select the port range.
   -  **Description**: Enter a description for the firewall rule if necessary.

#. Click **OK**.

.. |image1| image:: /images/en-us_image_0241356603.png

.. |image2| image:: /images/en-us_image_0000001167495475.png

.. |image3| image:: /images/en-us_image_0241356603.png

.. |image4| image:: /images/en-us_image_0000001120894978.png

