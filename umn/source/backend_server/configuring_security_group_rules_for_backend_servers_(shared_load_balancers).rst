Configuring Security Group Rules for Backend Servers (Shared Load Balancers)
============================================================================

Scenarios
---------

Before you add servers to a backend server group, ensure that their security groups have inbound rules that allow traffic from 100.125.0.0/16, and specify the health check protocol and port. Otherwise, health checks will be affected, and backend servers cannot receive requests from the load balancer. If UDP is used for health checks, inbound security group rules must also allow the ICMP traffic.

If you have no VPCs when creating a server, the system will automatically create a VPC with default security rules. Default security group rules allow only communications among the servers in the VPC. You also need to configure inbound rules to enable the load balancer to communicate with these servers over the frontend port and health check port.

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

#. Under **Inbound Rules**, click **Add Rule**.

   **TCP, HTTP, or HTTPS listeners**

   -  If the health check port is not the one used by each backend server, add inbound rules to allow TCP traffic over the health check port and the ports used by backend servers.
   -  If you do not specify a health check port, add inbound rules to allow TCP traffic over the ports used by backend servers.
   -  The inbound rules must also allow access from 100.125.0.0/16. Otherwise, health checks will fail.

   **UDP listeners**

   -  If the health check port is not the one used by each backend server, add inbound rules to allow UDP traffic over the health check port and the ports used by backend servers.
   -  If you do not specify a health check port, add inbound rules to allow UDP traffic over the ports used by backend servers.
   -  The inbound rules must also allow access from 100.125.0.0/16. Otherwise, health checks will fail.
   -  You need also to add an inbound rule to allow ICMP traffic.

#. Click **OK**.

Firewall Rule
-------------

You can associate one or more subnets with a firewall for controlling traffic in and out of the subnets. Similar to security groups, firewalls provide access control functions, but add an additional layer of defense to your VPC. Default firewall rules reject all inbound and outbound traffic. If the subnet of a load balancer or associated backend servers has a firewall associated, the load balancer cannot receive traffic from the Internet or route traffic to backend servers, and backend servers cannot receive traffic from and respond to the load balancer.

You can configure an inbound firewall rule to permit access from 100.125.0.0/16.

ELB translates public IP addresses that access backend servers into IP addresses in 100.125.0.0/16. You cannot configure firewall rules to prevent public IP addresses from accessing backend servers to allow traffic from 100.125.0.0/16 to all backend servers.

#. Log in to the management console.
#. In the upper left corner of the page, click |image3| and select the desired region and project.
#. Under **Network**, click **Virtual Private Cloud**.
#. In the navigation pane on the left, choose **Access Control** > **Firewalls**.
#. Locate the firewall, and click the firewall name to switch to the firewall details page.
#. On the **Inbound Rules** or **Outbound Rules** tab page, click **Add Rule** to add a rule.

   -  **Action**: Select **Allow**.
   -  **Protocol**: The protocol must be the same as the frontend protocol you select when you add the listener.
   -  **Source**: Set the value to **100.125.0.0/16**.
   -  **Source Port Range**: Select the port range.
   -  **Destination**: Enter the default value **0.0.0.0/0**. Traffic will be destined for all IP addresses.
   -  **Destination Port Range**: Select the port range.
   -  **Description**: Enter a description for the firewall rule if necessary.

#. Click **OK**.

.. |image1| image:: /images/en-us_image_0241356603.png

.. |image2| image:: /images/en-us_image_0000001167495475.png

.. |image3| image:: /images/en-us_image_0241356603.png

