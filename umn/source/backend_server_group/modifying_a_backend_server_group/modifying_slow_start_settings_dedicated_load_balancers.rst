:original_name: elb_ug_hdg_0005_04.html

.. _elb_ug_hdg_0005_04:

Modifying Slow Start Settings (Dedicated Load Balancers)
========================================================

Scenario
--------

This section describes how you can modify the slow start settings.

For details, see :ref:`Slow Start (Dedicated Load Balancers) <en-us_topic_0000001794819209>`.

.. note::

   -  This section applies only to dedicated load balancers.
   -  You can also configure slow start when adding a listener or creating a backend server group.

Enabling Slow Start
-------------------

#. Log in to the management console.

#. In the upper left corner of the page, click |image1| and select the desired region and project.

#. Click |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. In the navigation pane on the left, choose **Elastic Load Balancing** > **Backend Server Groups**.

#. On the **Backend Server Groups** page, locate the target backend server group and click **Edit** in the **Operation** column.

#. In the **Modify Backend Server Group** dialog box, enable slow start and set the slow start duration.

   The slow start duration ranges from 30 to 1200 in seconds. When the slow start duration elapses, the load balancer sends full share of requests to backend servers and exits the slow start mode.

#. Click **OK**.

Disabling slow start
--------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image3| and select the desired region and project.
#. Click |image4| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. In the navigation pane on the left, choose **Elastic Load Balancing** > **Backend Server Groups**.
#. On the **Backend Server Groups** page, locate the target backend server group and click **Edit** in the **Operation** column.
#. In the **Modify Backend Server Group** dialog box, disable slow start.
#. Click **OK**.

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001747739748.png
.. |image3| image:: /_static/images/en-us_image_0000001747739624.png
.. |image4| image:: /_static/images/en-us_image_0000001747739748.png
