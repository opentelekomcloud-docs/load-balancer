How Do I Troubleshoot an Unhealthy Backend Server?
==================================================

Symptom
-------

If a client cannot access a backend server through a load balancer, the backend server is declared unhealthy. You can check the health check result of the backend server on the ELB console.

-  Dedicated load balancers

   On the **Load Balancers** page, click the name of the load balancer to view its details. Click **Backend Server Groups** and locate the server group. In the **Basic Information** area, view the health check result of the backend server.

-  Shared load balancers

   On the **Load Balancers** page, click the name of the load balancer to view its details. Click **Backend Server Groups** and locate the server group. In the **Basic Information** area, view the health check result of the backend server.

Background
----------

The load balancer uses IP addresses in 100.125.0.0/16 to send heartbeats to backend servers and check their health. To ensure that health checks can be performed normally, IP addresses in 100.125.0.0/16 must be allowed to access the backend servers.

|image1|

Security group rules configured for backend servers associated with dedicated load balancers are different from those configured for backend servers associated with shared load balancers.

-  Classic and shared load balancers: Ensure that security group rules allow access from IP addresses in 100.125.0.0/16.

-  Dedicated load balancers: Ensure that security group rules allow access from IP addresses in the CIDR block of the VPC where the backend server resides.

   For details about how to configure security groups for backend servers associated with dedicated load balancers, see `Configuring Security Group Rules for Backend Servers (Dedicated Load Balancers) <elb_ug_hd_0007.html>`__.

If a backend server is considered unhealthy, ELB will not route traffic to it until it is declared healthy again.

If you change the weight of a healthy backend server to 0, the health check result of this server becomes **Unhealthy**.

|image2|

-  When a backend server is detected as unhealthy, the load balancer will stop routing requests to this server.
-  If health checks are disabled, the load balancer will consider the backend server healthy by default and still route requests to it.
-  ELB uses IP addresses in 100.125.0.0/16 to perform health checks and route requests to backend servers.
-  If the **Obtain Client IP Address** option is enabled for TCP and UDP listeners of both dedicated and shared load balancers, client IP addresses instead of the IP addresses in 100.125.0.0/16 are used to communicate with the backend server.
-  Traffic is not routed to a backend server with a weight of 0, and the health check result for the backend server is not relevant.

Troubleshooting Procedure
-------------------------

Possible causes are sequenced based on their occurrence probability.

Check these causes one by one until the fault persists.

|image3|

You may need to change the health check configuration. It takes a while for the modification to take effect. The required time depends on health check interval and timeout duration. View the health check result in the backend server list of the load balancer.

| **Figure 1** Troubleshooting process
| |image4|


.. _en-us_topic_0018127975__table11639162722113:

.. table:: **Table 1** Troubleshooting process

   +----------------------------------------+----------------------------------------------------------------------------+
   | Possible Cause                         | Solution                                                                   |
   +========================================+============================================================================+
   | Backend server group                   | `Checking Whether the Backend Server Group Is Associated with a            |
   |                                        | Listener <#en-us_topic_0018127975__section190812168556>`__                 |
   +----------------------------------------+----------------------------------------------------------------------------+
   | Health check configuration             | `Checking the Health Check                                                 |
   |                                        | Configuration <#en-us_topic_0018127975__section10449191315558>`__          |
   +----------------------------------------+----------------------------------------------------------------------------+
   | Security group rules                   | `Checking Security Group                                                   |
   |                                        | Rules <#en-us_topic_0018127975__section2948957185917>`__                   |
   +----------------------------------------+----------------------------------------------------------------------------+
   | Network ACL rules                      | `Checking Firewall Rules <#en-us_topic_0018127975__section125775401003>`__ |
   +----------------------------------------+----------------------------------------------------------------------------+
   | Backend server listening configuration | `Checking the Backend                                                      |
   |                                        | Server <#en-us_topic_0018127975__section12988243125410>`__                 |
   +----------------------------------------+----------------------------------------------------------------------------+
   | Backend server firewall configuration  | `Checking the Firewall on the Backend                                      |
   |                                        | Server <#en-us_topic_0018127975__section250265525>`__                      |
   +----------------------------------------+----------------------------------------------------------------------------+
   | Backend server route configuration     | `Checking the Backend Server                                               |
   |                                        | Route <#en-us_topic_0018127975__section25361331629>`__                     |
   +----------------------------------------+----------------------------------------------------------------------------+
   | Backend server load                    | `Checking the Backend Server                                               |
   |                                        | Load <#en-us_topic_0018127975__section1047211561921>`__                    |
   +----------------------------------------+----------------------------------------------------------------------------+
   | Backend server **host.deny** file      | `Checking the host.deny                                                    |
   |                                        | File <#en-us_topic_0018127975__section18101222533>`__                      |
   +----------------------------------------+----------------------------------------------------------------------------+

Checking Whether the Backend Server Group Is Associated with a Listener
-----------------------------------------------------------------------

Check whether the backend server group that the unhealthy backend server belongs to is associated with a listener.

-  If the backend server group is not associated with a listener, check whether a listener has been added to the load balancer.

   -  If a listener has been added. Associate the backend server group with the listener.
   -  If no listeners exist. Add a listener. Select **Use existing** and then select the backend server group when you add the listener.

-  If the backend server group has been associated with a listener, proceed with the following operations.

Checking the Health Check Configuration
---------------------------------------

**Classic load balancers**: In the **Listeners** area, locate the listener with an unhealthy backend server associated and click **View** in the **Health Check** column. The **Health Check** dialog box is displayed. Check the following parameters:

-  Health check protocol and port

   The health check port must be the one used on the backend server, and it cannot be customized.

   Check whether the health check port is the one that the load balancer is listening to. If the two ports are inconsistent, the health check will become abnormal.

-  **Check Path**. If HTTP is used for health checks, you must check this parameter. A simple static HTML file is recommended.\ |image5|

   Enter an absolute path.

   Examples:

   If the URL is **http://www.example.com/chat/try/**, the health check path is **/chat/try/**.

   If the URL is **http://192.168.63.187:9096/chat/index.html**, the health check path is **/chat/index.html**.

**Shared load balancers**: Click the name of the load balancer to view its details. Click **Backend Server Groups** and then click the name of the server group. On the **Basic Information** page, click **Configure** on the right of **Health Check**. Check the following parameters:

-  **Protocol**
-  **Port** The port must be the one used on the backend server, and it cannot be customized. Check whether the health check port is the one that the load balancer is listening to. If the two ports are inconsistent, the health check will become abnormal.
-  **Check Path** If HTTP is used for health checks, you must check this parameter. A simple static HTML file is recommended.

|image6|

-  If the health check protocol is HTTP, the port and the path are used for health checks.

-  If the health check protocol is TCP, only the port is used for health checks.

-  If health check protocol is HTTP and the health check port is normal, change the path or change the health check protocol to TCP.

-  Enter an absolute path.

   Examples:

   If the URL is **http://www.example.com/chat/try/**, the health check path is **/chat/try/**.

   If the URL is **http://192.168.63.187:9096/chat/index.html**, the health check path is **/chat/index.html**.

Checking Security Group Rules
-----------------------------

-  **Dedicated Load balancers**

   The inbound rules of the security group that the backend server belongs to must allow traffic to the VPC where the load balancer resides.

-  **SharedELB**

   -  **TCP, HTTP, or HTTPS listeners**: Verify that the inbound rule of the security group containing the backend server allows access from 100.125.0.0/16 and allows the traffic from the health check port.

      -  If the health check port is the same as the backend port, the inbound rule must allow traffic from the backend port, for example, 80.

      -  If the health check port is different from the backend port, the inbound rule must allow traffic from both the health check port and backend port, for example, 443 and 80.\ |image7|

         You can check the protocol and port in the basic information area of the backend server group.

      **Figure 2** Example inbound rule
      |image8|
   -  **UDP listeners**: Verify that the inbound rule of the security group allows traffic from the health check protocol, health check port, and 100.125.0.0/16. In addition, the ICMP traffic must be allowed in the inbound direction.\ **Figure 3** Example inbound rule that allows ICMP traffic
      |image9|

-  **Classic load balancers on a private network**: Verify that the TCP traffic is allowed over the health check port in the VPC.\ **Figure 4** Example inbound rule that allows TCP traffic within the VPC
   |image10|

-  **TCP, HTTP, or HTTPS listeners**: Verify that the inbound rule of the security group containing the backend server allows access from 100.125.0.0/16 and allows the traffic from the health check port.

   -  If the health check port is the same as the backend port, the inbound rule must allow traffic from the backend port, for example, 80.

   -  If the health check port is different from the backend port, the inbound rule must allow traffic from both the health check port and backend port, for example, 443 and 80.\ |image11|

      You can check the protocol and port in the basic information area of the backend server group.

   **Figure 5** Example inbound rule
   |image12|
-  **UDP listeners**: Verify that the inbound rule of the security group allows traffic from the health check protocol, health check port, and 100.125.0.0/16. In addition, the ICMP traffic must be allowed in the inbound direction.\ **Figure 6** Example inbound rule that allows ICMP traffic
   |image13|
-  **Classic load balancers on a private network**: Verify that the TCP traffic is allowed over the health check port in the VPC.\ **Figure 7** Example inbound rule that allows TCP traffic within the VPC
   |image14|

|image15|

-  Access to the backend server from IP addresses in 100.125.0.0/16 must be allowed. Load balancers communicate with backend servers using these IP addresses. After traffic is routed to backend servers, source IP addresses are converted to IP addresses starting with 100.125. In addition, the IP address of the health check node is allocated from 100.125.0.0/16.
-  If you are not sure about the security group rules, change the protocol and port range to **All** just for testing purposes.
-  For UDP listeners, see `How Does ELB Perform UDP Health Checks? What Are the Precautions for UDP Health Checks? <elb_faq_0024.html>`__

Checking Firewall Rules
-----------------------

You can associate one or more subnets with a firewall for controlling traffic in and out of the subnets. Similar to security groups, firewalls provide access control functions, but add an additional layer of defense to your VPC. Default firewall rules reject all inbound and outbound traffic. If the subnet of a load balancer or associated backend servers has a firewall associated, the load balancer cannot receive traffic from the Internet or route traffic to backend servers, and backend servers cannot receive traffic from and respond to the load balancer.

You can configure an inbound firewall rule to permit access from 100.125.0.0/16.

#. Log in to the management console.
#. In the upper left corner of the page, click |image16| and select the desired region and project.
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

Checking the Backend Server
---------------------------

|image17|

If the backend server runs a Windows OS, use a browser to access **https://**\ *Backend server IP address*:*Health check port*. If a 2xx or 3xx code is returned, the backend server is running normally.

-  Run the following command on the backend server to check whether the health check port is listened on:

   .. code::

      netstat -anlp | grep port

   If the health check port and **LISTEN** are displayed, the backend port is in the listening state. As shown in `Figure 8 <#en-us_topic_0018127975__fig1698814434541>`__, TCP port 880 is listened on.

   | If you do not specify a health check port, backend ports are used by default.\ **Figure 8** Backend server port listened on
   | |image18|
     **Figure 9** Backend server port not listened on
   | |image19|

-  For HTTP health checks, run the following command on the backend server to check the status code:

   .. code::

      curl Private IP address of the backend server:Health check port/Health check path -iv

   To perform an HTTP health check, the load balancer initiates a GET request to the backend server. If the following response status codes are displayed, the backend server is considered healthy:

   TCP listeners: 200

   Public network classic load balancers: 2xx or 3xx

   Dedicated load balancers: 200 for TCP/UDP/HTTP/HTTPS health checks

   Shared load balancers: 200, 202, or 401 for HTTP health checks, and 200 for TCP health checks

   | **Figure 10** Unhealthy backend server
   | |image20|
     **Figure 11** Healthy backend server
   | |image21|

-  If HTTP is used for health checks and the backend server is detected unhealthy, perform the following steps to configure a TCP health check:

   On the **Listeners** tab page, modify the listener, select the backend server group for which TCP health check has been configured, or add a backend server group and select TCP as the health check protocol. After you complete the configuration, wait for a while and check the health check result.

Checking the Firewall on the Backend Server
-------------------------------------------

The firewall or other security software on the backend server may mask IP addresses in 100.125.0.0/16. Ensure that access from 100.125.0.0/16 is allowed in the security group containing the backend server.

Checking the Backend Server Route
---------------------------------

Check whether the default route configured for the primary NIC has been manually modified. If the default route is changed, health check packets may fail to reach the backend server.

Run the following command on the backend server to check whether the default route points to the gateway (For Layer 3 communications, the default route must be configured to point to the gateway):

.. code::

   ip route

Alternatively, run the following command:

.. code::

   route -n

If the command output does not contain the highlighted route or the IP address to which the route points is not the gateway address of the VPC subnet, change the route to the default one.

| **Figure 12** Example default route pointing to the gateway
| |image22|
  **Figure 13** Example default route not pointing to the gateway
| |image23|

Checking the Backend Server Load
--------------------------------

Check the load of the backend server. If the load is high, connections or requests for health checks may time out.

Checking the **host.deny** File
-------------------------------

Verify that IP addresses in 100.125.0.0/16 are not written to the **/etc/hosts.deny** file on the backend server.

.. |image1| image:: /images/caution_3.0-en-us.png
.. |image2| image:: /images/note_3.0-en-us.png
.. |image3| image:: /images/note_3.0-en-us.png
.. |image4| image:: /images/en-us_image_0000001161784976.png

.. |image5| image:: /images/note_3.0-en-us.png
.. |image6| image:: /images/note_3.0-en-us.png
.. |image7| image:: /images/note_3.0-en-us.png
.. |image8| image:: /images/en-us_image_0000001150291788.png

.. |image9| image:: /images/en-us_image_0000001196171669.png

.. |image10| image:: /images/en-us_image_0000001150131972.png

.. |image11| image:: /images/note_3.0-en-us.png
.. |image12| image:: /images/en-us_image_0291936910.png

.. |image13| image:: /images/en-us_image_0291937212.png

.. |image14| image:: /images/en-us_image_0291937584.png

.. |image15| image:: /images/note_3.0-en-us.png
.. |image16| image:: /images/en-us_image_0241356603.png

.. |image17| image:: /images/note_3.0-en-us.png
.. |image18| image:: /images/en-us_image_0277560434.png

.. |image19| image:: /images/en-us_image_0277560435.png

.. |image20| image:: /images/en-us_image_0277560436.png

.. |image21| image:: /images/en-us_image_0277560437.png

.. |image22| image:: /images/en-us_image_0171437555.png

.. |image23| image:: /images/en-us_image_0171437556.png

