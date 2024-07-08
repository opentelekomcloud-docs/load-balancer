:original_name: elb_ug_hd2_0003_01.html

.. _elb_ug_hd2_0003_01:

Adding Backend Servers
======================

Scenario
--------

You can add backend servers to a backend server group to process requests from clients.

When you use ELB to route requests, ensure that at least one backend server is running normally and can receive requests routed by the load balancer.

If a backend server is removed, it is disassociated from the load balancer and can still run normally. However, it cannot receive requests from the load balancer. You can add the backend server to the backend server group again when traffic increases or the reliability needs to be enhanced.

Constraints and Limitations
---------------------------

Only servers in the same VPC as the load balancer can be added.

Procedure
---------

#. Log in to the management console.

#. In the upper left corner of the page, click |image1| and select the desired region and project.

#. Click |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. In the navigation pane on the left, choose **Elastic Load Balancing** > **Backend Server Groups**.

#. On the **Backend Server Groups** page, click the name of the backend server group.

#. Switch to the **Backend Servers** tab and click **Add** on the right.

#. Search for backend servers using keywords.

#. Specify the weights and ports for the backend servers, and click **Finish**.

   Backend server ports can be set in batches.

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001794660485.png
