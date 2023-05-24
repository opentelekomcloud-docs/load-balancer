:original_name: elb_qs_0003.html

.. _elb_qs_0003:

Using Dedicated Load Balancers (Advanced Level)
===============================================

Scenarios
---------

You have two web applications that are deployed on separated ECSs but use the same domain name for access. You can set different URLs to process requests.

To forward requests based on URLs, you need to create a load balancer, add an HTTP or HTTPS listener, and add forwarding policies to specify the URLs.

An HTTP listener is used as an example to describe how to route requests from two URLs (**/ELB01** and **/ELB02**) of the same domain name (www.example.com) to different backend servers.

Prerequisites
-------------

-  You have added security group rules to allow traffic from the ports used by the two ECSs. (Alternatively, you can enable all ports first and then disable the ports that are no longer used after service deployment.)
-  You have verified that the security group containing the ECSs allows access traffic from the VPC where the load balancer works and that the health check function is normal.

   .. note::

      If **IP as a Backend** is not enabled for a dedicated load balancer that has a TCP or UDP listener, there is no need to configure security group rules to allow traffic from the VPC where the load balancer backend subnet works to the backend servers.

Creating ECSs
-------------

ECSs are used as backend servers to process requests. Each ECS needs an EIP for accessing the Internet and configuring the application on the ECS.

#. Log in to the management console.

#. In the upper left corner of the page, click |image1| and select the desired region and project.

#. Hover on |image2| in the upper left corner to display **Service List** and choose **Computing** > **Elastic Cloud Server**.

#. Click **Create ECS**, configure the parameters, and click **Create Now**.

   The following table lists the specifications of the two ECSs.

   .. table:: **Table 1** ECS specifications

      =========== ================
      Item        Example Value
      =========== ================
      Name        ECS01 and ECS02
      OS          CentOS 7.2 64bit
      vCPUs       2
      Memory      4 GB
      System disk 40 GB
      Data disk   100 GB
      Bandwidth   5 Mbit/s
      =========== ================

#. Submit your request.

Deploying the Application
-------------------------

Deploy Nginx on the two ECSs and edit two HTML pages so that a page with message "Welcome to ELB test page one!" is returned when ECS01 is accessed, and the other page with message "Welcome to ELB test page two!" is returned when ECS02 is accessed.

#. Log in to the ECSs.

#. Install and start Nginx.

   a. Run the **wget** command to download the Nginx installation package for your operating system in use. CentOS 7.6 is used as an example here.

      .. code-block::

         wget http://nginx.org/packages/centos/7/noarch/RPMS/nginx-release-centos-7-0.el7.ngx.noarch.rpm

   b. Run the following command to create the Nginx yum repository:

      .. code-block::

         rpm -ivh nginx-release-centos-7-0.el7.ngx.noarch.rpm

   c. Run the following command to install Nginx:

      .. code-block::

         yum -y install nginx

   d. Run the following commands to start Nginx and configure automatic Nginx enabling upon ECS startup:

      .. code-block::

         systemctl start nginx
         systemctl enable nginx

   e. Enter **http://**\ *EIP bound to the ECS* in the address box of your browser. If the following page is displayed, Nginx has been installed.


      .. figure:: /_static/images/en-us_image_0000001206435130.png
         :alt: **Figure 1** Nginx installed successfully

         **Figure 1** Nginx installed successfully

#. Modify the HTML page of ECS01.

   Move the **index.html** file from the default root directory of Nginx **/usr/share/nginx/html** to the **ELB01** directory and modify the file to identify access to ECS01.

   a. Create the **ELB01** directory and copy the **index.html** file to this directory:

      **mkdir /usr/share/nginx/html/ELB01**

      **cp /usr/share/nginx/html/\ index.html /usr/share/nginx/html/ELB01**/

   b. Open the **index.html** file.

      **vim /usr/share/nginx/html\ /ELB01/index.html**

   c. Press **i** to enter editing mode.

   d. Modify the **index.html** file to be as follows:

      .. code-block::

          ...
             <body>
                 <h1>Welcome to <strong>ELB</strong> test page one!</h1>

                 <div class="content">
                     <p>This page is used to test the <strong>ELB</strong>!</p>

                     <div class="alert">
                         <h2>ELB01</h2>
                         <div class="content">
                             <p><strong>ELB test (page one)!</strong></p>
                             <p><strong>ELB test (page one)!</strong></p>
                             <p><strong>ELB test (page one)!</strong></p>
                         </div>
                     </div>
                 </div>
             </body>

   e. Press **Esc** to exit editing mode. Then, enter **:wq** to save the settings and exit the file.

#. Modify the HTML page of ECS02.

   Move the **index.html** file from the default root directory of Nginx **/usr/share/nginx/html** to the **ELB02** directory and modify the file to identify access to ECS02.

   a. Create the **ELB02** directory and copy the **index.html** file to this directory:

      **mkdir /usr/share/nginx/html/ELB02**

      **cp /usr/share/nginx/html/\ index.html /usr/share/nginx/html/ELB02**/

   b. Open the **index.html** file.

      **vim /usr/share/nginx/html\ /ELB02/index.html**

   c. Press **i** to enter editing mode.

   d. Modify the **index.html** file to be as follows:

      .. code-block::

         ...
             <body>
                 <h1>Welcome to <strong>ELB</strong> test page two!</h1>

                 <div class="content">
                     <p>This page is used to test the <strong>ELB</strong>!</p>

                     <div class="alert">
                         <h2>ELB02</h2>
                         <div class="content">
                             <p><strong>ELB test (page two)!</strong></p>
                             <p><strong>ELB test (page two)!</strong></p>
                             <p><strong>ELB test (page two)!</strong></p>
                         </div>
                      </div>
                 </div>
             </body>

   e. Press **Esc** to exit editing mode. Then, enter **:wq** to save the settings and exit the file.

#. Use your browser to access **http://**\ *ECS01 EIP*\ **/ELB01/** and **http://**\ *ECS02 EIP*\ **/ELB02/** to verify that Nginx has been deployed.

   If the modified HTML pages are displayed, Nginx has been deployed.

   -  HTML page of ECS01


      .. figure:: /_static/images/en-us_image_0166358924.png
         :alt: **Figure 2** Nginx successfully deployed on ECS01

         **Figure 2** Nginx successfully deployed on ECS01

   -  HTML page of ECS02


      .. figure:: /_static/images/en-us_image_0166358926.png
         :alt: **Figure 3** Nginx successfully deployed on ECS02

         **Figure 3** Nginx successfully deployed on ECS02

Creating a Load Balancer
------------------------

The load balancer needs an EIP to access the application deployed on the ECSs over the Internet. You can determine whether to bind an EIP to the load balancer based on your requirements. For details, see :ref:`Load Balancing on a Public or Private Network <elb_pro_01_0004>`.

#. In the upper left corner of the page, click |image3| and select the desired region and project.
#. Hover on |image4| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Click **Create Elastic Load Balancer** and then configure the parameters.
#. Click **Create Now**.
#. Confirm the configuration and submit your request.
#. View the newly created load balancer in the load balancer list.

.. note::

   After you create a dedicated load balancer, configure the security group that contains the ECSs to allow traffic from the VPC where the load balancer works.

Procedure
---------

#. Log in to the management console.

#. In the upper left corner of the page, click |image5| and select the desired region and project.

#. Hover on |image6| in the upper left corner to display **Service List** and choose **Computing** > **Elastic Cloud Server**.

#. In the ECS list, locate the ECS and click its name.

   The ECS details page is displayed.

#. Click **Security Groups**, locate the security group, and view security group rules.

#. Click the security group rule ID or **Modify Security Group Rule**. The security group details page is displayed.

#. On the **Inbound Rules** tab page, click **Add Rule**. Configure an inbound rule based on :ref:`Table 2 <elb_qs_0003__elb_ug_hd_0007_en-us_topic_0000001420502298_en-us_topic_0000001390784280_table22703095416>`.

   .. _elb_qs_0003__elb_ug_hd_0007_en-us_topic_0000001420502298_en-us_topic_0000001390784280_table22703095416:

   .. table:: **Table 2** Security group rules

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

#. Click **OK**.

Firewall Rules
--------------

To control traffic in and out of a subnet, you can associate a firewall with the subnet. Similar to security groups, firewall rules control access to subnets and add an additional layer of defense to your subnets. Default firewall rules reject all inbound and outbound traffic. If the subnet of a load balancer or associated backend servers has a firewall associated, the load balancer cannot receive traffic from the Internet or route traffic to backend servers, and backend servers cannot receive traffic from and respond to the load balancer.

Configure an inbound firewall rule to allow traffic from the VPC where the load balancer works to backend servers.

#. Log in to the management console.
#. In the upper left corner of the page, click |image7| and select the desired region and project.
#. Click |image8| in the upper left corner of the page and choose **Network** > **Virtual Private Cloud**.
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

Adding a Listener
-----------------

Add a listener to the created load balancer. When you add the listener, create a backend server group, configure a health check, and add the two ECSs to the created backend server group.

Configure two forwarding policies to forward HTTP requests to the two ECSs, for example, requests from **www.example.com/ELB01/** to ECS01, and those from **www.example.com/ELB02/** to ECS02.


.. figure:: /_static/images/en-us_image_0198607881.png
   :alt: **Figure 4** Traffic forwarding

   **Figure 4** Traffic forwarding

#. Hover on |image9| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the created load balancer and click its name.
#. Under **Listeners**, click **Add Listener**.
#. Configure the listener and click **Next**.

   -  **Name**: Enter a name, for example, **listener-HTTP**.
   -  **Frontend Protocol/Port**: Select a protocol and enter a port for the load balancer to receive requests. For example, set it to **HTTP** and **80**.

#. Create a backend server group, configure a health check, and click **Finish**.

   -  Backend server group

      -  **Name**: Enter a name, for example, **server_group-ELB**.
      -  **Load Balancing Algorithm**: Select an algorithm that the load balancer will use to route requests, for example, **Weighted round robin**.

   -  Health check

      -  **Protocol**: Select a protocol for the load balancer to perform health checks on backend servers. If the load balancer uses TCP, HTTP, or HTTPS to receive requests, the health check protocol can be TCP or HTTP. Here we use HTTP as an example. Note that the protocol cannot be changed after the listener is added.
      -  **Domain Name**: Enter a domain name that will be used for health checks, for example, www.example.com.
      -  **Port**: Enter a port for the load balancer to perform health checks on backend servers, for example, **80**.

Adding Forwarding Policies
--------------------------

#. .. _elb_qs_0003__en-us_elb_02_0001_li1279175813279:

   Click the name of the newly added listener and then click **Add** next to **Forwarding Policies**.

#. Configure the forwarding policy and click **Next**.

   -  **Name**: Enter a name for the forwarding policy, for example, **forwarding_policy-ELB01**.
   -  **Domain Name**: Enter a domain name that will be used to forward the requests, for example, www.example.com. The domain name in the request must exactly match that specified in the forwarding policy.
   -  **URL**: You can also specify a URL to forward the requests, for example, **/ELB01/**.
   -  **URL Matching Rule**: Select a rule for matching the specified URL string with the URL in the request. Three options are available, **Exact match**, **Prefix match**, and **Regular expression match**. **Exact match** enjoys the highest priority, and **Regular expression match** the lowest priority. Select **Exact match** here.

#. Add the backend server group and configure a health check.

   -  Backend server group

      -  **Name**: Enter a name, for example, **server_group-ELB01**.
      -  **Load Balancing Algorithm**: Select an algorithm that the load balancer will use to route requests, for example, **Weighted round robin**.

   -  Health check

      -  **Protocol**: Select a protocol for the load balancer to perform health checks on backend servers. If the load balancer uses TCP, HTTP, or HTTPS to receive requests, the health check protocol can be TCP or HTTP. Here we use HTTP as an example. Note that the protocol cannot be changed after the listener is added.
      -  **Domain Name**: Enter a domain name that will be used for health checks, for example, **www.example.com**.
      -  **Port**: Enter a port for the load balancer to perform health checks on backend servers, for example, **80**.

#. Select the newly added forwarding policy. On the **Backend Server Groups** tab page on the right, click **Add**.

#. .. _elb_qs_0003__en-us_elb_02_0001_li19903154544217:

   Select the server you want to add, set the backend port, and click **Finish**.

   -  Backend server: ECS01
   -  Backend port: Set it to **80**. Backend servers will use this port to communicate with the load balancer.

#. Repeat :ref:`1 <elb_qs_0003__en-us_elb_02_0001_li1279175813279>` to :ref:`5 <elb_qs_0003__en-us_elb_02_0001_li19903154544217>` to add another forwarding policy, create a backend server group, and add ECS02 to the backend server group. Configure the parameters.

Verifying Load Balancing
------------------------

After the load balancer is configured, you can access the domain name or the specified URL to check whether the two ECSs are accessible.

#. Modify the **C:\\Windows\\System32\\drivers\\etc\\hosts** file on your PC to map the domain name to the load balancer EIP.

   View the load balancer EIP on the **Summary** page of the load balancer.


   .. figure:: /_static/images/en-us_image_0166358967.png
      :alt: **Figure 5** **hosts** file on your PC

      **Figure 5** **hosts** file on your PC

#. On the CLI of your PC, run the following command to check whether the domain name is mapped to the load balancer EIP:

   **ping www.example.com**

   If data packets are returned, the domain name has been mapped to the load balancer EIP.

#. Use your browser to access **http://www.example.com/ELB01/**. If the following page is displayed, the load balancer has routed the request to ECS01.


   .. figure:: /_static/images/en-us_image_0166358972.png
      :alt: **Figure 6** Accessing ECS01

      **Figure 6** Accessing ECS01

   .. note::

      **ELB01/** indicates that the default directory named **ECS01** is accessed, while **ELB01** indicates the file name. Therefore, the slash (/) following **ELB01** must be retained.

#. Use your browser to access **http://www.example.com/ELB02/**. If the following page is displayed, the load balancer has routed the request to ECS02.


   .. figure:: /_static/images/en-us_image_0166358975.png
      :alt: **Figure 7** Accessing ECS02

      **Figure 7** Accessing ECS02

.. |image1| image:: /_static/images/en-us_image_0000001211126503.png
.. |image2| image:: /_static/images/en-us_image_0000001206511791.png
.. |image3| image:: /_static/images/en-us_image_0000001211126503.png
.. |image4| image:: /_static/images/en-us_image_0000001417088430.png
.. |image5| image:: /_static/images/en-us_image_0000001211126503.png
.. |image6| image:: /_static/images/en-us_image_0000001167495475.png
.. |image7| image:: /_static/images/en-us_image_0000001211126503.png
.. |image8| image:: /_static/images/en-us_image_0000001508946757.png
.. |image9| image:: /_static/images/en-us_image_0000001417088430.png
