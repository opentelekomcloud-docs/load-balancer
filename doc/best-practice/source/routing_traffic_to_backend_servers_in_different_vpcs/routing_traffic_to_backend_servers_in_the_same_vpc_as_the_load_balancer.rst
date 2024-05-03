:original_name: elb_bp_0303.html

.. _elb_bp_0303:

Routing Traffic to Backend Servers in the Same VPC as the Load Balancer
=======================================================================

Scenarios
---------

You can route traffic to backend servers in the VPC where the load balancer is running.

Solution
--------

- A dedicated load balancer **ELB-Test** is running in a VPC named **vpc-Test** (10.1.0.0/16).
- The backend server **ECS-Test** is also running in **vpc-Test** (10.1.0.0/16).  
- **ECS-Test** needs to be added to the backend server group associated with **ELB-Test**.



.. figure:: /_static/images/en-us_image_0000001625619218.png
   :alt: **Figure 1** Adding a backend server in the same VPC as the load balancer

   **Figure 1** Adding a backend server in the same VPC as the load balancer

Advantages
----------

You can add servers in the same VPC as the load balancer to the backend server group of the load balancer and then route incoming traffic to the servers.


Resource and Cost Planning
--------------------------

.. Note::

   To calculate the fees you can visit Open Telekom Cloud `Price calculator <https://open-telekom-cloud.com/en/prices/price-calculator>`_.

The required resources are as follows:

.. table:: **Table 1** Resource planning

   +------------------------+-------------------+-----------------------------------------------------------------------------------+-----------------+
   | Resource Type          | Resource Name     | Description                                                                       | Quantity        |
   +========================+===================+===================================================================================+=================+
   | VPC                    | vpc-Test          | The VPC where **ELB-Test** and **ECS-Test** are running:                          | 1               |
   |                        |                   |                                                                                   |                 |
   |                        |                   | 10.1.0.0/16                                                                       |                 |
   +------------------------+-------------------+-----------------------------------------------------------------------------------+-----------------+
   | ELB                    | ELB-Test          | The dedicated load balancer named **ELB-Test**                                    | 1               |
   |                        |                   |                                                                                   |                 |
   +------------------------+-------------------+-----------------------------------------------------------------------------------+-----------------+
   | EIP                    | EIP-Test          | The EIP bound to **ELB-Test**                                                     | 1               |
   |                        |                   |                                                                                   |                 |
   |                        |                   |                                                                                   |                 |
   +------------------------+-------------------+-----------------------------------------------------------------------------------+-----------------+
   | ECS                    | ECS-Test          | The ECS works in **vpc-Test**                                                     | 1               |
   |                        |                   |                                                                                   |                 |
   +------------------------+-------------------+-----------------------------------------------------------------------------------+-----------------+

Operation Process
-----------------


.. figure:: /_static/images/en-us_image_0000001674059073.png
   :alt: **Figure 2** Process for adding backend servers in the same VPC as the load balancer

   **Figure 2** Process for adding backend servers in the same VPC as the load balancer

Creating a VPC
--------------

#. Log in to the management console.

#. Under **Networking**, select **Virtual Private Cloud**. On the **Virtual Private Cloud** page displayed, click **Create VPC**.

#. Configure the parameters as follows and click **Create Now**. For details on how to create a VPC, see the `Virtual Private Cloud User Guide <https://docs.otc.t-systems.com/virtual-private-cloud/umn/vpc_and_subnet/vpc/creating_a_vpc.html>`__.

   -  **Name**: **vpc-Test**
   -  **IPv4 CIDR Block**: **10.1.0.0/16**
   -  Configure other parameters as required.


   .. figure:: /_static/images/en-us_image_0000001625459326.png
      :alt: **Figure 3** Creating **vpc-Test**

      **Figure 3** Creating **vpc-Test**

Creating an ECS
---------------

#. Under **Computing**, click **Elastic Cloud Server**.

#. In the upper right corner, click **Create ECS**.

#. Configure the parameters as required. For details, see `Elastic Cloud Server User Guide <https://docs.otc.t-systems.com/elastic-cloud-server/umn/getting_started/creating_an_ecs/overview.html>`__.

   Select **vpc-Test** for VPC and set **Name** to **ECS-Test**.


   .. figure:: /_static/images/en-us_image_0000001625299518.png
      :alt: **Figure 6** Creating ECS-Test

      **Figure 6** Creating ECS-Test

#. Deploy Nginx on the ECS.


   .. figure:: /_static/images/en-us_image_0000001625619246.png
      :alt: **Figure 7** Deploying Nginx on **ECS-Test**

      **Figure 7** Deploying Nginx on **ECS-Test**

Creating a Dedicated Load Balancer and Adding an HTTP Listener and a Backend Server Group to the Load Balancer
--------------------------------------------------------------------------------------------------------------

#. Under **Networking**, click **Elastic Load Balance**.

#. In the upper right corner, click **Create Elastic Load Balancer**.

#. Configure the parameters as follows. For details, see `Elastic Load Balance User Guide <https://docs.otc.t-systems.com/elastic-load-balancing/umn/load_balancer/creating_a_dedicated_load_balancer.html>`__.

   -  **Type**: **Dedicated**
   -  **IP as a Backend**: Enable
   -  **VPC**: **vpc-Test**
   -  **Name**: **ELB-Test**
   -  Configure other parameters as required.


   .. figure:: /_static/images/en-us_image_0000001673939093.png
      :alt: **Figure 8** Creating a dedicated load balancer named **ELB-Test**

      **Figure 8** Creating a dedicated load balancer named **ELB-Test**

#. Add an HTTP listener and a backend server group to the created dedicated load balancer. For details, see `Elastic Load Balance User Guide <https://docs.otc.t-systems.com/elastic-load-balancing/umn/listener/adding_an_http_listener.html>`__.

Adding the ECS to the Backend Server Group
------------------------------------------

#. Locate the dedicated load balancer and click its name **ELB-Test**.

#. On the **Listeners** tab page, locate the HTTP listener added to the dedicated load balancer and click its name.

#. In the **Backend Server Groups** tab on the right, click **Add Backend Server**, configure the parameters, and click **OK**. For details, see *Elastic Load Balance User Guide*.

   -  **Backend Server **: **ECS-Test**
   -  **Backend Port**: the port enabled for Nginx on **ECS-Test**
   -  **Weight**: Configure this parameter as required.


   .. figure:: /_static/images/en-us_image_0000001674059081.png
      :alt: **Figure 9** Adding IP as backend servers

      **Figure 9** Adding IP as backend servers

Verifying Traffic Routing
-------------------------

.. Note::

   EIP is not necessary as long as you don't want to access the ELB externally, you can always access the ELB from its private IP.

#. Locate the dedicated load balancer **ELB-Test** and click **More** in the **Operation** column.

#. Select **Bind IPv4 EIP** to bind an EIP to **ELB-Test**.


   .. figure:: /_static/images/en-us_image_0000001674259073.png
      :alt: **Figure 10** EIP bound to the load balancer

      **Figure 10** EIP bound to the load balancer


#. Enter **http://<EIP>/** in the address box of your browser to access the dedicated load balancer. If the following page is displayed, the load balancer routes the request to **ECS-Test**, which processes the request and returns the requested page.

   .. note::

      In case of unhealthy connection of the backend server group, check if the ECS subnet and ELB subnet are associated with the above created route tables.

   .. figure:: /_static/images/en-us_image_0000001625459334.png
      :alt: **Figure 11** Verifying traffic routing

      **Figure 11** Verifying traffic routing

