:original_name: elb_ug_hd3_0003_04.html

.. _elb_ug_hd3_0003_04:

Changing Backend Server Weights
===============================

Scenario
--------

You can change the weights specified for backend servers based on their capability to process requests.

Constraints and Limitations
---------------------------

-  The weight ranges from **0** to **100**. If you set the weight of a backend server to **0**, new requests will not be routed to this server.
-  The weights can only be specified when you select weighted round robin, weighted least connections, or source IP hash as the load balancing algorithm. For more information about load balancing algorithms, see :ref:`Backend Server Weights <elb_ug_hd3_0001__en-us_topic_0000001384422734_section84064491587>`.

Procedure
---------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Click |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. In the navigation pane on the left, choose **Elastic Load Balancing** > **Backend Server Groups**.
#. On the **Backend Server Groups** page, click the name of the backend server group.
#. Switch to the **Backend Servers** tab and click **Backend Servers**.
#. Select the backend servers and click **Modify Port/Weight** above the backend server list.
#. In the displayed dialog box, change the weights as you need.

   -  Changing weights:

      -  Changing the weight of a single backend server: Set the weight in the **Weight** column.
      -  Changing the weights of multiple backend servers: Set the weight next to **Batch Modify Weights** and click **OK**.

      .. note::

         You can change the weights of multiple backend servers to **0** so they will not receive requests from the load balancer.

#. Click **OK**.

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001794660485.png
