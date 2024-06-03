:original_name: elb_bp_0302.html

.. _elb_bp_0302:

Routing Traffic to Backend Servers in Different VPCs from the Load Balancer
===========================================================================

Scenarios
---------

You can use ELB to route traffic to backend servers in two VPCs connected over a VPC peering connection.

Solution
--------

-  A dedicated load balancer named **ELB-Test** is running in **VPC-Test-01** (172.18.0.0/24).
-  An ECS named **ECS-Test** is running in **VPC-Test-02** (172.17.0.0/24).
-  **IP as a Backend** is enabled for the dedicated load balancer **ELB-Test**, and **ECS-Test** in **VPC-Test-02** (172.17.0.0/24) is added to the backend server group associated with **ELB-Test**.


.. figure:: /_static/images/en-us_image_0000001674059065.png
   :alt: **Figure 1** Topology

   **Figure 1** Topology

Advantages
----------

You can enable **IP as a Backend** for the dedicated load balancer to route incoming traffic to servers in different VPCs from the load balancer.

Resource and Cost Planning
--------------------------

.. Note::

   To calculate the fees you can visit Open Telekom Cloud `Price calculator <https://open-telekom-cloud.com/en/prices/price-calculator>`_.

The required resources are as follows:

.. table:: **Table 1** Resource planning

   +------------------------+-------------------+--------------------------------------------------------------------------------------------------------------+-----------------+
   | Resource Type          | Resource Name     | Description                                                                                                  | Quantity        |
   +========================+===================+==============================================================================================================+=================+
   | VPC                    | VPC-Test-01       | The VPC where **ELB-Test** is running:                                                                       | 1               |
   |                        |                   |                                                                                                              |                 |
   |                        |                   | 172.18.0.0/24                                                                                                |                 |
   +------------------------+-------------------+--------------------------------------------------------------------------------------------------------------+-----------------+
   |                        | VPC-Test-02       | The VPC where **ECS-Test** is running:                                                                       | 1               |
   |                        |                   |                                                                                                              |                 |
   |                        |                   | 172.17.0.0/24                                                                                                |                 |
   +------------------------+-------------------+--------------------------------------------------------------------------------------------------------------+-----------------+
   | VPC peering connection | Peering-Test      | The connection that connects the VPC where **ELB-Test** is running and the VPC where **ECS-Test** is running | 1               |
   |                        |                   |                                                                                                              |                 |
   |                        |                   | **Local VPC**: **172.18.0.0/24**                                                                             |                 |
   |                        |                   |                                                                                                              |                 |
   |                        |                   | **Peer VPC**: **172.17.0.0/24**                                                                              |                 |
   +------------------------+-------------------+--------------------------------------------------------------------------------------------------------------+-----------------+
   | Route table            | Route-VPC-Test-01 | The route table of **VPC-Test-01**                                                                           | 1               |
   |                        |                   |                                                                                                              |                 |
   |                        |                   | **Destination**: **172.17.0.0/24**                                                                           |                 |
   +------------------------+-------------------+--------------------------------------------------------------------------------------------------------------+-----------------+
   |                        | Route-VPC-Test-02 | The route table of **VPC-Test-02**                                                                           | 1               |
   |                        |                   |                                                                                                              |                 |
   |                        |                   | **Destination**: **172.18.0.0/24**                                                                           |                 |
   +------------------------+-------------------+--------------------------------------------------------------------------------------------------------------+-----------------+
   | ELB                    | ELB-Test          | The dedicated load balancer                                                                                  | 1               |
   +------------------------+-------------------+--------------------------------------------------------------------------------------------------------------+-----------------+
   | EIP                    | EIP-Test          | The EIP bound to **ELB-Test**                                                                                | 1               |
   |                        |                   |                                                                                                              |                 |
   |                        |                   |                                                                                                              |                 |
   +------------------------+-------------------+--------------------------------------------------------------------------------------------------------------+-----------------+
   | ECS                    | ECS-Test          | The ECS works in **VPC-Test-02**                                                                             | 1               |
   |                        |                   |                                                                                                              |                 |
   +------------------------+-------------------+--------------------------------------------------------------------------------------------------------------+-----------------+

Operation Process
-----------------


.. figure:: /_static/images/en-us_image_0000001674259057.png
   :alt: **Figure 2** Process of associating servers in a VPC that is different from the dedicated load balancer

   **Figure 2** Process of associating servers in a VPC that is different from the dedicated load balancer

Creating VPCs
-------------

#. Log in to the management console.

#. .. _elb_bp_0302__en-us_topic_0000001338079025_en-us_topic_0000001197419640_en-us_topic_0000001235854281_li15678518185720:

   Under **Networking**, select **Virtual Private Cloud**. On the **Virtual Private Cloud** page displayed, click **Create VPC**.

#. .. _elb_bp_0302__en-us_topic_0000001338079025_en-us_topic_0000001197419640_en-us_topic_0000001235854281_li1469314167118:

   Configure the parameters as follows and click **Create Now**. For details on how to create a VPC, see the `Virtual Private Cloud User Guide <https://docs.otc.t-systems.com/virtual-private-cloud/umn/vpc_and_subnet/vpc/creating_a_vpc.html>`__.

   -  **Name**: **VPC-Test-01**
   -  **IPv4 CIDR Block**: **172.18.0.0/24**
   -  Configure other parameters as required.


   .. figure:: /_static/images/en-us_image_0000001625459302.png
      :alt: **Figure 3** Creating **VPC-Test-01**

      **Figure 3** Creating **VPC-Test-01**

#. Repeat :ref:`2 <elb_bp_0302__en-us_topic_0000001338079025_en-us_topic_0000001197419640_en-us_topic_0000001235854281_li15678518185720>` and :ref:`3 <elb_bp_0302__en-us_topic_0000001338079025_en-us_topic_0000001197419640_en-us_topic_0000001235854281_li1469314167118>` to create the other VPC.

   -  **Name**: **VPC-Test-02**
   -  **IPv4 CIDR Block**: **172.17.0.0/24**
   -  Configure other parameters as required.


   .. figure:: /_static/images/en-us_image_0000001674139185.png
      :alt: **Figure 4** Creating **VPC-Test-02**

      **Figure 4** Creating **VPC-Test-02**

Creating a VPC Peering Connection
---------------------------------

#. In the navigation pane on the left, click **VPC Peering**.

#. In the upper right corner, click **Create VPC Peering Connection**.

#. Configure the parameters as follows and click **OK**. For details on how to create a VPC peering connection, see the `Virtual Private Cloud User Guide <https://docs.otc.t-systems.com/virtual-private-cloud/umn/vpc_peering_connection/creating_a_vpc_peering_connection_with_another_vpc_in_your_account.html>`__.

   -  **Name**: **Peering-Test**
   -  **Local VPC**: **VPC-Test-01**
   -  **Peer VPC**: **VPC-Test-02**
   -  Configure other parameters as required.


   .. figure:: /_static/images/en-us_image_0000001625779198.png
      :alt: **Figure 5** Creating **Peering-Test**

      **Figure 5** Creating **Peering-Test**

Adding Routes for the VPC Peering Connection
--------------------------------------------

#. In the navigation pane on the left, click **Route Tables**.

#. .. _elb_bp_0302__en-us_topic_0000001338079025_en-us_topic_0000001197419640_en-us_topic_0000001235854281_li122357513543:

   In the upper right corner, click **Create Route Table**.

#. .. _elb_bp_0302__en-us_topic_0000001338079025_en-us_topic_0000001197419640_en-us_topic_0000001235854281_li1235135185416:

   Configure the parameters as follows and click **OK**. For details on how to create a route table, see the `Virtual Private Cloud User Guide <https://docs.otc.t-systems.com/virtual-private-cloud/umn/route_tables/creating_a_custom_route_table.html>`__.

   -  **Name**: **Route-VPC-Test-01**
   -  **VPC**: **VPC-Test-01**
   -  **Destination**: **172.17.0.0/24**
   -  **Next Hop Type**: **VPC peering connection**
   -  **Next Hop**: **Peering-Test**


   .. figure:: /_static/images/en-us_image_0000001625299482.png
      :alt: **Figure 6** Creating **Route-VPC-Test-01**

      **Figure 6** Creating **Route-VPC-Test-01**

#. Repeat :ref:`3 <elb_bp_0302__en-us_topic_0000001338079025_en-us_topic_0000001197419640_en-us_topic_0000001235854281_li122357513543>` and :ref:`4 <elb_bp_0302__en-us_topic_0000001338079025_en-us_topic_0000001197419640_en-us_topic_0000001235854281_li1235135185416>` to create the other route table.

   -  **Name**: **Route-VPC-Test-02**
   -  **VPC**: **VPC-Test-02**
   -  **Destination**: **172.18.0.0/24**
   -  **Next Hop Type**: **VPC peering connection**
   -  **Next Hop**: **Peering-Test**

Creating an ECS
---------------

#. Under **Computing**, click **Elastic Cloud Server**.

#. In the upper right corner, click **Create ECS**.

#. Select **VPC-Test-02** as the **VPC** and set **ECS Name** to **ECS-Test**. Configure other parameters as required. For details, see `Elastic Cloud Server User Guide <https://docs.otc.t-systems.com/elastic-cloud-server/umn/getting_started/creating_an_ecs/overview.html>`__.


   .. figure:: /_static/images/en-us_image_0000001625619214.png
      :alt: **Figure 7** Creating ECS-Test

      **Figure 7** Creating ECS-Test

#. Deploy Nginx on the ECS.


   .. figure:: /_static/images/en-us_image_0000001673939081.png
      :alt: **Figure 8** Deploying Nginx on **ECS-Test**

      **Figure 8** Deploying Nginx on **ECS-Test**

Creating a Dedicated Load Balancer and Adding an HTTP Listener and a Backend Server Group to the Load Balancer
--------------------------------------------------------------------------------------------------------------

#. Under **Networking**, click **Elastic Load Balance**.

#. In the upper right corner, click **Create Elastic Load Balancer**.

#. Configure the parameters as follows. For details, see `Elastic Load Balance User Guide <https://docs.otc.t-systems.com/elastic-load-balancing/umn/load_balancer/creating_a_dedicated_load_balancer.html>`__.

   -  **Type**: **Dedicated**
   -  **IP as a Backend**: Enable
   -  **VPC**: **VPC-Test-01**
   -  **Name**: **ELB-Test**
   -  Configure other parameters as required.


   .. figure:: /_static/images/en-us_image_0000001674059069.png
      :alt: **Figure 9** Creating **ELB-Test**

      **Figure 9** Creating **ELB-Test**

#. Add an HTTP listener and a backend server group to the dedicated load balancer. For details, see `Elastic Load Balance User Guide <https://docs.otc.t-systems.com/elastic-load-balancing/umn/listener/adding_an_http_listener.html>`__.


   .. figure:: /_static/images/en-us_image_0000001674259061.png
      :alt: **Figure 10** HTTP listener and backend server group

      **Figure 10** HTTP listener and backend server group

Adding the ECS to the Backend Server Group
------------------------------------------

#. Locate the created dedicated load balancer and click its name **ELB-Test**.

#. On the **Listeners** tab page, locate the HTTP listener added to the dedicated load balancer and click its name.

#. In the **Backend Server Groups** tab on the right, click **IP as Backend Servers**.


   .. figure:: /_static/images/en-us_image_0000001625459306.png
      :alt: **Figure 11** IP as backend servers

      **Figure 11** IP as backend servers

#. Click **Add IP as Backend Server**, configure the parameters, and click **OK**. For details, see *Elastic Load Balance User Guide*.

   -  **Backend Server IP Address**: Private IP address of **ECS-Test** (172.17.0.205)
   -  **Backend Port**: the port enabled for Nginx on **ECS-Test**
   -  **Weight**: Set this parameter as required.


   .. figure:: /_static/images/en-us_image_0000001674139189.png
      :alt: **Figure 12** Adding ECS-Test using its IP address

      **Figure 12** Adding ECS-Test using its IP address

Verifying Traffic Routing
-------------------------

.. Note::

   EIP is not necessary as long as you don't want to access the ELB externally, you can always access the ELB from its private IP.


#. Locate the dedicated load balancer **ELB-Test** and click **More** in the **Operation** column.

#. Select **Bind IPv4 EIP** to bind an EIP to **ELB-Test**.


   .. figure:: /_static/images/en-us_image_0000001625779202.png
      :alt: **Figure 13** EIP bound to the load balancer

      **Figure 13** EIP bound to the load balancer

#. Enter **http://<EIP>/** in the address box of your browser to access the dedicated load balancer. If the following page is displayed, the load balancer routes the request to **ECS-Test**, which processes the request and returns the requested page.

   .. note::

      In case of unhealthy connection of the backend server group, check if the ECS subnet and ELB subnet are associated with the above created route tables.

   .. figure:: /_static/images/en-us_image_0000001625299490.png
      :alt: **Figure 14** Verifying that the request is routed to ECS-Test

      **Figure 14** Verifying that the request is routed to ECS-Test
