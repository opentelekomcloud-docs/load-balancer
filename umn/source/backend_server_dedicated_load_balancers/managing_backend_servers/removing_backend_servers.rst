:original_name: elb_ug_hd3_0003_03.html

.. _elb_ug_hd3_0003_03:

Removing Backend Servers
========================

Scenario
--------

You can remove a backend server that is no longer needed from a backend server group.

If a backend server is removed, it is disassociated from the load balancer and can still run normally. However, it cannot receive requests from the load balancer. You can add the backend server to the backend server group again when traffic increases or the reliability needs to be enhanced.

Procedure
---------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Click |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. In the navigation pane on the left, choose **Elastic Load Balancing** > **Backend Server Groups**.
#. On the **Backend Server Groups** page, click the name of the backend server group.
#. Switch to the **Backend Servers** tab and click **Backend Servers**.
#. Select the backend servers you want to remove and click **Remove** above the backend server list.
#. In the displayed dialog box, click **Yes**.

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001794660485.png
