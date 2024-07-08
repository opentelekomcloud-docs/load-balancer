:original_name: elb_ug_hdg_0005_03.html

.. _elb_ug_hdg_0005_03:

Modifying Sticky Session Settings
=================================

Scenario
--------

This section describes how you can modify the sticky session settings.

.. note::

   -  This section applies to dedicated and shared load balancers.
   -  You can also configure sticky sessions when adding a listener or creating a backend server group.

Enabling Sticky Session
-----------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Click |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. In the navigation pane on the left, choose **Elastic Load Balancing** > **Backend Server Groups**.
#. On the **Backend Server Groups** page, locate the target backend server group and click **Edit** in the **Operation** column.
#. In the **Modify Backend Server Group** dialog box, enable sticky session, select the sticky session type, and set the session stickiness duration.
#. Click **OK**.

Disabling Sticky Session
------------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image3| and select the desired region and project.
#. Click |image4| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. In the navigation pane on the left, choose **Elastic Load Balancing** > **Backend Server Groups**.
#. On the **Backend Server Groups** page, locate the target backend server group and click **Edit** in the **Operation** column.
#. In the **Modify Backend Server Group** dialog box, disable sticky session.
#. Click **OK**.

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001747739748.png
.. |image3| image:: /_static/images/en-us_image_0000001747739624.png
.. |image4| image:: /_static/images/en-us_image_0000001747739748.png
