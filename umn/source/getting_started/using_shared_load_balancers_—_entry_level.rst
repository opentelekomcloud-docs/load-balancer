Using Shared Load Balancers — Entry Level
=========================================

Scenarios
---------

You have a web application, which often needs to handle heavy traffic and is deployed on two ECSs for load balancing.

You can create a shared load balancer to distribute traffic evenly across the two ECSs, which eliminates SPOFs and makes your application more available.

Prerequisites
-------------

-  You have added security group rules to allow traffic from the ports used by the two ECSs. (Alternatively, you can enable all ports first and then disable the ports that are no longer used.)
-  The security group containing the two ECSs allows traffic from 100.125.0.0/16. (ELB uses these IP addresses to perform health checks and route requests to backend servers.)

Creating ECSs
-------------

ECSs are used as backend servers.

Each ECS needs an EIP for accessing the Internet, so that The EIP bound to the ECS is required only for configuring ECS backend services in this example. You need to determine whether to bind an EIP to the ECS based on the service plan.

Determine whether you need to bind an EIP to your load balancer by referring to `Load Balancing on a Public or Private Network <en-us_elb_01_0004.html>`__.

#. Log in to the management console.

#. In the upper left corner of the page, click |image1| and select the desired region and project.

#. Hover on |image2| in the upper left corner to display **Service List** and choose **Computing** > **Elastic Cloud Server**.

#.

   .. container::


      Click **Create ECS**, configure the parameters, and click **Create Now**.

      The following table lists the specifications of the two ECSs.


.. _en-us_topic_0052569751__table9439114212376:

      .. table:: **Table 1** ECS specifications

         =========== =================
         **Item**    **Example Value**
         =========== =================
         Name        ECS01 and ECS02
         OS          CentOS 7.2 64bit
         vCPUs       2
         Memory      4 GB
         System disk 40 GB
         Data disk   100 GB
         Bandwidth   5 Mbit/s
         =========== =================

#. Submit your request.

Deploying the Application
-------------------------

Deploy Nginx on the two ECSs and edit two HTML pages for the web application so that a page with message "Welcome to ELB test page one!" is returned when ECS01 is accessed, and the other page with message "Welcome to ELB test page two!" is returned when ECS02 is accessed.

#. Log in to the ECSs.

#. Install and start Nginx.

   a. Install Nginx:

      **yum -y install nginx**

   b. Start Nginx:

      **systemctl start nginx.service**

   c. Enter **http://**\ *EIP bound to the ECS* in the address box of your browser.If the following page is displayed, Nginx has been installed.\ **Figure 1** Nginx installed successfully
      |image3|

#. Modify the HTML page of ECS01.Modify the **index.html** file in the default root directory of Nginx **/usr/share/nginx/html** to identify access to ECS01.

   a. Open the **index.html** file.

      **vim /usr/share/nginx/html\ /\ index.html**

   b. Press **i** to enter editing mode.

   c. Modify the **index.html** file to be as follows:

      .. code::

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

   d. Press **Esc** to exit editing mode. Then, enter **:wq** to save the settings and exit the file.

#. Modify the HTML page of ECS02.Modify the **index.html** file in the default root directory of Nginx **/usr/share/nginx/html** to identify access to ECS02.

   a. Open the **index.html** file.

      **vim /usr/share/nginx/html\ /\ index.html**

   b. Press **i** to enter editing mode.

   c. Modify the **index.html** file to be as follows:

      .. code::

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

   d. Press **Esc** to exit editing mode. Then, enter **:wq** to save the settings and exit the file.

#. Use your browser to access **http://**\ *ECS01 EIP* and **http://**\ *ECS02 EIP* to verify that Nginx has been deployed.

   If the modified HTML pages are displayed, Nginx has been deployed.

   -  HTML page of ECS01\ **Figure 2** Nginx successfully deployed on ECS01
      |image4|
   -  HTML page of ECS02\ **Figure 3** Nginx successfully deployed on ECS02
      |image5|

Creating a Load Balancer
------------------------

#. In the upper left corner of the page, click |image6| and select the desired region and project.
#. Hover on |image7| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Click **Create Elastic Load Balancer** and then configure the parameters.
#. Click **Create Now**.
#. Confirm the configuration and submit your request.
#. View the newly created load balancer in the load balancer list.

Adding a Listener
-----------------

Add a listener to the created load balancer. When you add the listener, create a backend server group, configure a health check, and add the two ECSs to the created backend server group.

| **Figure 4** Traffic forwarding
| |image8|

#. Hover on |image9| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the created load balancer (**elb-01**) and click its name.
#. Under **Listeners**, click **Add Listener**.
#. Configure the listener and click **Next**.

   -  **Name**: Enter a name, for example, **listener-HTTP**.
   -  **Frontend Protocol/Port**: Select a protocol and enter a port for the load balancer to receive requests. For example, set it to **HTTP** and **80**.

#. Create a backend server group and configure a health check.

   -  Backend server group

      -  **Name**: Enter a name, for example, **server_group-ELB**.
      -  **Load Balancing Algorithm**: Select an algorithm that the load balancer will use to route requests, for example, **Weighted round robin**.

   -  Health check

      -  **Protocol**: Select a protocol for the load balancer to perform health checks on backend servers. If the load balancer uses TCP, HTTP, or HTTPS to receive requests, the health check protocol can be TCP or HTTP. Here we use HTTP as an example. Note that the protocol cannot be changed after the listener is added.
      -  **Domain Name**: Enter a domain name that will be used for health checks, for example, **www.example.com**.
      -  **Port**: Enter a port for the load balancer to perform health checks on backend servers, for example, **80**.

#. Click the name of the newly added listener. On the **Backend Server Groups** tab page on the right, click **Add**.
#. Select the servers you want to add, set the backend port, and click **Finish**.

   -  Backend servers: Select **ECS01** and **ECS02**.
   -  Backend port: Set it to **80**. Backend servers will use this port to communicate with the load balancer.

Verifying Load Balancing
------------------------

After the load balancer is configured, you can access the domain name to check whether the two ECSs are accessible.

#. Modify the **C:\Windows\System32\drivers\etc\hosts** file on your PC to map the domain name to the load balancer EIP.View the load balancer EIP on the basic information page of the load balancer.\ **Figure 5** **hosts** file on your PC
   |image10|

#. On the CLI of your PC, run the following command to check whether the domain name is mapped to the load balancer EIP:

   **ping www.example.com**

   If data packets are returned, the domain name has been mapped to the load balancer EIP.

#. Use your browser to access **http://www.example.com**. If the following page is displayed, the load balancer has routed the request to ECS01.\ **Figure 6** Accessing ECS01
   |image11|

#. Use your browser to access **http://www.example.com**. If the following page is displayed, the load balancer has routed the request to ECS02.\ **Figure 7** Accessing ECS02
   |image12|

.. |image1| image:: /images/en-us_image_0238408792.png

.. |image2| image:: /images/en-us_image_0000001206511791.png

.. |image3| image:: /images/en-us_image_0207374995.jpg

.. |image4| image:: /images/en-us_image_0167655332.png

.. |image5| image:: /images/en-us_image_0167655334.png

.. |image6| image:: /images/en-us_image_0241225827.png

.. |image7| image:: /images/en-us_image_0000001120894978.png

.. |image8| image:: /images/en-us_image_0198607824.png
   :class: vsd

.. |image9| image:: /images/en-us_image_0000001120894978.png

.. |image10| image:: /images/en-us_image_0167652140.png

.. |image11| image:: /images/en-us_image_0167652142.png

.. |image12| image:: /images/en-us_image_0167652143.png

