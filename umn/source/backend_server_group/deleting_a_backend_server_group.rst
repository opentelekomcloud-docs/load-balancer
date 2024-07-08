:original_name: elb_ug_hdg_0008.html

.. _elb_ug_hdg_0008:

Deleting a Backend Server Group
===============================

Scenario
--------

This section describes how you can delete a backend server group.

Constraints and Limitations
---------------------------

-  Before you delete a backend server group, you need to:

   -  Disassociate it from the listener. For details, see :ref:`Changing a Backend Server Group <elb_ug_hdg_0006>`.
   -  Ensure the backend server group is not used by a forwarding policy of an HTTP or HTTPS listener.

-  Remove all backend servers from the backend server group.

Procedure
---------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Click |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. In the navigation pane on the left, choose **Elastic Load Balancing** > **Backend Server Groups**.
#. On the **Backend Server Groups** page, locate the backend server group and click **Delete** in the **Operation** column.
#. In the displayed dialog box, click **Yes**.

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001794660485.png
