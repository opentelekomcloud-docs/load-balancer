:original_name: elb_ug_hdg_0005_02.html

.. _elb_ug_hdg_0005_02:

Changing the Load Balancing Algorithm
=====================================

Scenario
--------

This section describes how you can change the load balancing algorithm.

For details about load balancing algorithms, see :ref:`Load Balancing Algorithms <elb_ug_jt_0003>`.

Procedure
---------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Click |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. In the navigation pane on the left, choose **Elastic Load Balancing** > **Backend Server Groups**.
#. On the **Backend Server Groups** page, locate the target backend server group and click **Edit** in the **Operation** column.
#. In the **Modify Backend Server Group** dialog box, change the load balancing algorithm.
#. Click **OK**.

.. note::

   The new load balancing algorithm takes effect immediately and will be used to route requests over new connections. However, the previous load balancing algorithm will still be used to route requests over established connections.

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001747739748.png
