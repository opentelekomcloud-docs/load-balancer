:original_name: elb_ug_hd3_0003_01.html

.. _elb_ug_hd3_0003_01:

Adding Backend Servers
======================

Scenario
--------

When you use ELB to route traffic to backend servers, you need to ensure that at least one backend server is running normally and can receive requests from the associated load balancer.

If the incoming traffic increases, you can add more backend servers to ensure the stability and reliability of applications and eliminate SPOFs. If the incoming traffic decreases, you can remove some backend servers to reduce costs.

Constraints and Limitations
---------------------------

-  The cloud servers must be in the same VPC as the backend server group.

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
