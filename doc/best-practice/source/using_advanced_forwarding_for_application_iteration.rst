:original_name: elb_bp_0400.html

.. _elb_bp_0400:

Using Advanced Forwarding for Application Iteration
===================================================

Scenarios
---------

As the business grows, you may need to upgrade your application. Both the old and new versions are used. Now, the new version is optimized based on users' feedback, and you want all the users to use the new version. In this process, you can use advanced forwarding to route requests to different versions.

Prerequisites
-------------

-  An Open Telekom Cloud account is available and real-name authentication has been completed.
-  The account balance is sufficient to pay for the resources involved in this best practice.
-  Six ECSs are available, with three having the application of the old version deployed and the other three having the new version deployed.

Process for Configuring Advanced Forwarding
-------------------------------------------


.. figure:: /_static/images/en-us_image_0000001221220190.png
   :alt: **Figure 1** Flowchart

   **Figure 1** Flowchart

.. table:: **Table 1** Resource planning

   +---------------------+-------------------------+-----------------------------------------------------------------------------------------+
   | Resource Name       | Resource Type           | Description                                                                             |
   +=====================+=========================+=========================================================================================+
   | ELB-Test            | Dedicated load balancer | Only dedicated load balancers support advanced forwarding.                              |
   +---------------------+-------------------------+-----------------------------------------------------------------------------------------+
   | Server_Group-Test01 | Backend server group    | Used to manage the ECSs where the application of the old version is deployed.           |
   +---------------------+-------------------------+-----------------------------------------------------------------------------------------+
   | Server_Group-Test02 | Backend server group    | Used to manage the ECSs where the application of the new version is deployed.           |
   +---------------------+-------------------------+-----------------------------------------------------------------------------------------+
   | ECS01               | ECS                     | Used to deploy the application of the old version and added to **Server_Group-Test01**. |
   +---------------------+-------------------------+-----------------------------------------------------------------------------------------+
   | ECS02               | ECS                     | Used to deploy the application of the old version and added to **Server_Group-Test01**. |
   +---------------------+-------------------------+-----------------------------------------------------------------------------------------+
   | ECS03               | ECS                     | Used to deploy the application of the old version and added to **Server_Group-Test01**. |
   +---------------------+-------------------------+-----------------------------------------------------------------------------------------+
   | ECS04               | ECS                     | Used to deploy the application of the new version and added to **Server_Group-Test02**. |
   +---------------------+-------------------------+-----------------------------------------------------------------------------------------+
   | ECS05               | ECS                     | Used to deploy the application of the new version and added to **Server_Group-Test02**. |
   +---------------------+-------------------------+-----------------------------------------------------------------------------------------+
   | ECS06               | ECS                     | Used to deploy the application of the new version and added to **Server_Group-Test02**. |
   +---------------------+-------------------------+-----------------------------------------------------------------------------------------+

.. note::

   In this practice, the dedicated load balancer is in the same VPC as the ECSs. You can also add servers in a different VPC or in an on-premises data center as needed. For details, see :ref:`Routing Traffic to Backend Servers in Different VPCs <elb_bp_0300>`.

Configuring a Dedicated Load Balancer
-------------------------------------

#. Log in to the management console.

#. Under **Networking**, click **Elastic Load Balance**.

#. In the upper right corner, click **Create Elastic Load Balancer**.

#. Create a dedicated load balancer **ELB-Test**. Configure the parameters as follows. For details, see `Elastic Load Balance User Guide <https://docs.otc.t-systems.com/elastic-load-balancing/umn/load_balancer/creating_a_dedicated_load_balancer.html>`__.

   -  **Type**: **Dedicated**
   -  **Name**: **ELB-Test**
   -  Configure other parameters as required.

#. Add an HTTP listener to **ELB-Test**. For details, see `Elastic Load Balance User Guide <https://docs.otc.t-systems.com/elastic-load-balancing/umn/listener/adding_an_http_listener.html>`__.


   .. figure:: /_static/images/en-us_image_0000001265145841.png
      :alt: **Figure 2** HTTP listener

      **Figure 2** HTTP listener

#. Enable advanced forwarding. For details, see `Elastic Load Balance User Guide <https://docs.otc.t-systems.com/elastic-load-balancing/umn/advanced_features_of_http_https_listeners/advanced_forwarding_dedicated_load_balancers/configuring_advanced_forwarding.html>`__


   .. figure:: /_static/images/en-us_image_0000001220740254.png
      :alt: **Figure 3** Enabling advanced forwarding

      **Figure 3** Enabling advanced forwarding

Creating Backend Server Groups and Adding Backend Servers
---------------------------------------------------------

#. Locate **ELB-Test** and click its name.

#. .. _elb_bp_0400__en-us_topic_0000001235854281_li42740713:

   On the **Listeners** tab, click **Create Backend Server Group** in the upper right corner.

   -  Name: **Server_Group-Test01**
   -  **Backend Protocol**: **HTTP**
   -  Configure other parameters as required.

#. Repeat :ref:`2 <elb_bp_0400__en-us_topic_0000001235854281_li42740713>` to create backend server group **Server_Group-Test02**.


   .. figure:: /_static/images/en-us_image_0000001265579817.png
      :alt: **Figure 4** Backend server groups

      **Figure 4** Backend server groups

#. Add **ECS01**, **ECS02**, and **ECS03** to backend server group **Server_Group-Test01**.

#. Add **ECS04**, **ECS05**, and **ECS06** to backend server group **Server_Group-Test02**

Forwarding Requests to Different Versions of the Application based on HTTP Request Methods
------------------------------------------------------------------------------------------

Configure two advanced forwarding policies with the HTTP request method as the condition to route GET and DELETE requests to the application of the old version and POST and PUT requests to the application of the new version. When the application of the new version runs stably, direct all the requests to the application.


.. figure:: /_static/images/en-us_image_0000001265745537.png
   :alt: **Figure 5** Forwarding requests based on HTTP request methods

   **Figure 5** Forwarding requests based on HTTP request methods

#. Locate the dedicated load balancer and click its name **ELB-Test**.

#. On the **Listeners** tab page, locate the HTTP listener added to the dedicated load balancer and click its name.

#. .. _elb_bp_0400__li1624715529284:

   On the **Forwarding Policies** tab page on the right, click **Add Forwarding Policy** to forward GET and DELETE requests to the old version.

   Select **GET** and **DELETE** from the **HTTP request method** drop-down list, select **Forward to backend server group** for **Action**, and select **Server_Group-Test01** from the **Backend Server Group** drop-down list.


   .. figure:: /_static/images/en-us_image_0000001265924809.png
      :alt: **Figure 6** Forwarding GET and DELETE requests to the application of the old version

      **Figure 6** Forwarding GET and DELETE requests to the application of the old version

#. .. _elb_bp_0400__li13546154719285:

   Click **Save**.

#. Repeat :ref:`Step 3 <elb_bp_0400__li1624715529284>` and :ref:`Step 4 <elb_bp_0400__li13546154719285>` to add a forwarding policy to forward PUT and POST requests to the application of the new version.

   Select **PUT** and **POST** from the **HTTP request method** drop-down list, select **Forward to backend server group** for **Action**, and select **Server_Group-Test02** from the **Backend Server Group** drop-down list.


   .. figure:: /_static/images/en-us_image_0000001265646757.png
      :alt: **Figure 7** Forwarding PUT and POST requests to the application of the new version

      **Figure 7** Forwarding PUT and POST requests to the application of the new version

Forwarding Requests to Different Versions of the Application based on HTTP Headers
----------------------------------------------------------------------------------

If the old version supports both Chinese and English, but the new version only supports English because the Chinese version is still under development, you can configure two advanced forwarding policies with the HTTP header as the condition to route requests to the Chinese application to the old version and requests to the English application to the new version. When the application of the new version supports the Chinese language, direct all the requests to the application.


.. figure:: /_static/images/en-us_image_0000001265465929.png
   :alt: **Figure 8** Smooth application transition between the old and new versions based on the HTTP request header

   **Figure 8** Smooth application transition between the old and new versions based on the HTTP request header

#. Locate the dedicated load balancer and click its name **ELB-Test**.

#. On the **Listeners** tab page, locate the HTTP listener added to the dedicated load balancer and click its name.

#. .. _elb_bp_0400__li116295223119:

   On the **Forwarding Policies** tab page on the right, and click **Add Forwarding Policy** to forward requests to the old version.

   Select **HTTP header** from the drop-down list, set the key to **Accept-Language** and value to **zh-cn**, set the action to **Forward to backend server group**, and select **Server_Group-Test01** as the backend server group.


   .. figure:: /_static/images/en-us_image_0000001265928345.png
      :alt: **Figure 9** Forwarding requests to the application of the old version

      **Figure 9** Forwarding requests to the application of the old version

#. Click **Save**.

#. Repeat :ref:`Step 3 <elb_bp_0400__li116295223119>` and :ref:`Step 4 <elb_bp_0400__li116295223119>` to add a forwarding policy to forward requests to the application of the new version.

   Select **HTTP header** from the drop-down list, set the key to **Accept-Language** and value to **en-us**, set the action to **Forward to backend server group**, and select **Server_Group-Test02** as the backend server group.


   .. figure:: /_static/images/en-us_image_0000001265488349.png
      :alt: **Figure 10** Forwarding requests to the application of the new version

      **Figure 10** Forwarding requests to the application of the new version

Forwarding Requests to Different Versions of the Application based on Query Strings
-----------------------------------------------------------------------------------

If the application is deployed across regions, you can configure two advanced forwarding policies with query string as the condition to forward requests to the application in region 1 to the old version and requests to the application in region 2 to the new version. When the application of the new version runs stably, direct all the requests to the new version.


.. figure:: /_static/images/en-us_image_0000001221308334.png
   :alt: **Figure 11** Forwarding requests based on query strings

   **Figure 11** Forwarding requests based on query strings

.. note::

   -  Dedicated load balancers can distribute traffic across VPCs or regions.
   -  In this example, you need to use Cloud Connect to connect the VPCs in the two regions and then use the dedicated load balancer to route traffic to backend servers in the two regions.

#. Locate the dedicated load balancer and click its name **ELB-Test**.

#. On the **Listeners** tab page, locate the HTTP listener added to the dedicated load balancer and click its name.

#. .. _elb_bp_0400__li1215314579314:

   On the **Forwarding Policies** tab page on the right, and click **Add Forwarding Policy** to forward requests to application of the old version.

   Select **Query string** from the drop-down list, set the key to **region** and value to **region01**, set **Action** to **Forward to backend server group**, and select **Server_Group-Test01** as the backend server group.


   .. figure:: /_static/images/en-us_image_0000001221328134.png
      :alt: **Figure 12** Forwarding requests to the old version

      **Figure 12** Forwarding requests to the old version

#. .. _elb_bp_0400__li1815385713110:

   Click **Save**.

#. Repeat :ref:`3 <elb_bp_0400__li1215314579314>` and :ref:`4 <elb_bp_0400__li1815385713110>` to add a forwarding policy to forward requests to the application of the new version.

   Select **Query string** from the drop-down list, set the key to **region** and value to **region02**, set **Action** to **Forward to backend server group**, and select **Server_Group-Test02** as the backend server group.


   .. figure:: /_static/images/en-us_image_0000001265648321.png
      :alt: **Figure 13** Forwarding requests to the new version

      **Figure 13** Forwarding requests to the new version
