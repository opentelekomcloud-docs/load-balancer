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

ECSs are used as backend servers.

Each ECS needs an EIP for accessing the Internet and configuring the application on the ECS.

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
      CPU         2vCPUs
      Memory      4 GiB
      System disk 40 GiB
      Data disk   100 GiB
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

   b. Run the following command to create the Nginx yum repository: CentOS 7.6 is used as an example here.

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


      .. figure:: /_static/images/en-us_image_0000001747739872.png
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

   d. Modify the **index.html** file.

      The following is the content to be modified:

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

   d. Modify the **index.html** file.

      The following is the content to be modified:

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


      .. figure:: /_static/images/en-us_image_0000001747380964.png
         :alt: **Figure 2** Nginx successfully deployed on ECS01

         **Figure 2** Nginx successfully deployed on ECS01

   -  HTML page of ECS02


      .. figure:: /_static/images/en-us_image_0000001794660689.png
         :alt: **Figure 3** Nginx successfully deployed on ECS02

         **Figure 3** Nginx successfully deployed on ECS02

Creating a Load Balancer
------------------------

Each ECS needs an EIP for accessing the Internet and configuring the application on the ECS. The load balancer needs an EIP to access the application deployed on the ECSs over the Internet. You can determine whether to bind an EIP to the load balancer based on your requirements. For details, see :ref:`Load Balancing on a Public or Private Network <elb_pro_01_0004>`.

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

#. Under **Computing**, click **Elastic Cloud Server**.

#. On the **Elastic Cloud Server** page, click the name of the ECS that has been added to a backend server group.

   The page providing details about the ECS is displayed.

#. Click **Security Groups**, locate the security group, and view security group rules.

#. Click the security group rule ID or **Modify Security Group Rule**. The security group details page is displayed.

#. On the **Inbound Rules** tab page, click **Add Rule**. Configure an inbound rule based on :ref:`Table 2 <elb_qs_0003__en-us_topic_0000001125381517_en-us_topic_0000001420502298_en-us_topic_0000001390784280_table22703095416>`.

   .. _elb_qs_0003__en-us_topic_0000001125381517_en-us_topic_0000001420502298_en-us_topic_0000001390784280_table22703095416:

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

   .. note::

      -  After a load balancer is created, do not change the subnet. If the subnet is changed, the IP addresses occupied by the load balancer will not be released, and traffic from the previous backend subnet is still need to be allowed to backend servers.
      -  Traffic from the new backend subnet is also need to be allowed to backend servers.

#. Click **OK**.

Firewall Rules
--------------

To control traffic in and out of a subnet, you can associate a firewall with the subnet. Firewalls rules control access to subnets and add an additional layer of defense to your subnets. The default firewall rule denies all inbound and outbound traffic. If the subnet of a load balancer or associated backend servers has a firewall rule associated, the load balancer cannot receive traffic from the Internet or route traffic to backend servers, and backend servers cannot receive traffic from and respond to the load balancer.

Configure an inbound firewall rule to allow traffic from the VPC where the load balancer resides to backend servers.

#. Log in to the management console.
#. In the upper left corner of the page, click |image6| and select the desired region and project.
#. Click |image7| in the upper left corner of the page and choose **Network** > **Virtual Private Cloud**.
#. In the navigation pane on the left, choose **Access Control** > **Firewalls**.
#. In the firewall list, click the name of the firewall to switch to the page showing its details.
#. On the **Inbound Rules** or **Outbound Rules** tab page, click **Add Rule** to add a rule.

   -  **Action**: Select **Allow**.
   -  **Protocol**: The protocol must be the same as the one you selected for the listener.
   -  **Source**: Set it to the VPC CIDR block.
   -  **Source Port Range**: Select a port range.
   -  **Destination**: Enter a destination address allowed in this direction. The default value is **0.0.0.0/0**, which indicates that traffic from all IP addresses is permitted.
   -  **Destination Port Range**: Select a port range.
   -  (Optional) **Description**: Describe the firewall rule if necessary.

#. Click **OK**.

Adding a Listener
-----------------

Add a listener to the created load balancer. When you add the listener, create a backend server group, configure a health check, and add the two ECSs to the created backend server group.

Configure two forwarding policies to forward HTTP requests to the two ECSs, for example, requests from **www.example.com/ELB01/** to ECS01, and those from **www.example.com/ELB02/** to ECS02.


.. figure:: /_static/images/en-us_image_0000001747739860.png
   :alt: **Figure 4** Traffic forwarding

   **Figure 4** Traffic forwarding

#. Hover on |image8| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Under **Listeners**, click **Add Listener**.
#. Configure the listener and click **Next**.

   -  **Name**: Enter a name, for example, **listener-HTTP**.
   -  **Frontend Protocol/Port**: Select a protocol and enter a port for the load balancer to receive requests. For example, set it to **HTTP** and **80**.

#. Create a backend server group, configure a health check, and click **Finish**.

   -  Backend Server Group

      -  **Name**: Enter a name, for example, **server_group-ELB**.
      -  **Load Balancing Algorithm**: Select an algorithm that the load balancer will use to route requests, for example, **Weighted round robin**.

   -  Health check

      -  **Protocol**: Select a protocol for the load balancer to perform health checks on backend servers. If the load balancer uses TCP, HTTP, or HTTPS to receive requests, the health check protocol can be TCP or HTTP. Here we use HTTP as an example. Note that the protocol cannot be changed after the listener is added.

      -  **Domain Name**: Enter a domain name that will be used for health checks, for example, www.example.com.

      -  **Health Check Port**: Enter a port for the load balancer to perform health checks on backend servers, for example, **80**.

         If you do not specify a health check port, the backend port will be used for health checks by default.

Adding a Forwarding Policy
--------------------------

#. Click the name of the newly added listener and then click **Add** next to **Forwarding Policies**.
#. Configure the forwarding policy and click **Next**.

   -  **Name**: Enter a name for the forwarding policy, for example, **forwarding_policy-ELB01**.
   -  **Domain Name**: Enter a domain name that will be used to forward the requests, for example, www.example.com. The domain name in the request must exactly match that specified in the forwarding policy.
   -  **URL**: You can also specify a URL to forward the requests, for example, **/ELB01/**.
   -  **URL Matching Rule**: Select a rule for matching the specified URL string with the URL in the request. Three options are available, **Exact match**, **Prefix match**, and **Regular expression match**. **Exact match** enjoys the highest priority, and **Regular expression match** the lowest priority. Select **Exact match** here.

#. Create a backend server group, configure a health check, and click **Finish**.

   -  Backend Server Group

      -  **Name**: Enter a name, for example, **server_group-ELB01**.
      -  **Load Balancing Algorithm**: Select an algorithm that the load balancer will use to route requests, for example, **Weighted round robin**.

   -  Health check

      -  **Protocol**: Select a protocol for the load balancer to perform health checks on backend servers. If the load balancer uses TCP, HTTP, or HTTPS to receive requests, the health check protocol can be TCP or HTTP. Here we use HTTP as an example. Note that the protocol cannot be changed after the listener is added.

      -  **Domain Name**: Enter a domain name that will be used for health checks, for example, **www.example.com**.

      -  **Health Check Port**: Enter a port for the load balancer to perform health checks on backend servers, for example, **80**.

         If you do not specify a health check port, the backend port will be used for health checks by default.

#. Select the newly added forwarding policy. On the **Backend Server Groups** tab page on the right, click **Add**.
#. Select the server you want to add, set the backend port, and click **Finish**.

   -  Backend server: ECS01
   -  Backend port: Set it to **80**. Backend servers will use this port to communicate with the load balancer.

#. Repeat the preceding steps to add another forwarding policy, create a backend server group, and add ECS02 to the backend server group.

Verifying Load Balancing
------------------------

After the load balancer is configured, you can access the domain name or the specified URL to check whether the two ECSs are accessible.

#. Modify the **C:\\Windows\\System32\\drivers\\etc\\hosts** file on your PC to map the domain name to the load balancer EIP.

   View the load balancer EIP on the **Summary** page of the load balancer.


   .. figure:: /_static/images/en-us_image_0000001794660705.png
      :alt: **Figure 5** **hosts** file on your PC

      **Figure 5** **hosts** file on your PC

#. On the CLI of your PC, run the following command to check whether the domain name is mapped to the load balancer EIP:

   **ping www.example.com**

   If data packets are returned, the domain name has been mapped to the load balancer EIP.

#. Use your browser to access **http://www.example.com/ELB01/**. If the following page is displayed, the load balancer has routed the request to ECS01.


   .. figure:: /_static/images/en-us_image_0000001794819797.png
      :alt: **Figure 6** Accessing ECS01

      **Figure 6** Accessing ECS01

   .. note::

      **ELB01/** indicates that the default directory named **ECS01** is accessed, while **ELB01** indicates the file name. Therefore, the slash (/) following **ELB01** must be retained.

#. Use your browser to access **http://www.example.com/ELB02/**. If the following page is displayed, the load balancer has routed the request to ECS02.


   .. figure:: /_static/images/en-us_image_0000001794660721.png
      :alt: **Figure 7** Accessing ECS02

      **Figure 7** Accessing ECS02

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001747380972.png
.. |image3| image:: /_static/images/en-us_image_0000001747739624.png
.. |image4| image:: /_static/images/en-us_image_0000001794660485.png
.. |image5| image:: /_static/images/en-us_image_0000001747739624.png
.. |image6| image:: /_static/images/en-us_image_0000001747739624.png
.. |image7| image:: /_static/images/en-us_image_0000001747739880.png
.. |image8| image:: /_static/images/en-us_image_0000001794660485.png
