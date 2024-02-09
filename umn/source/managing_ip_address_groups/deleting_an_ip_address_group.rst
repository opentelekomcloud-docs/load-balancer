:original_name: elb_ug_ip_0004.html

.. _elb_ug_ip_0004:

Deleting an IP Address Group
============================

Scenarios
---------

If you no longer need an IP address group, you can delete it. This section describes how you can delete an IP address group.

Constraints
-----------

An IP address group that has been used for controlling access to a listener cannot be deleted. You can view the listeners associated with an IP address group by referring to :ref:`Viewing the Details of an IP Address Group <elb_ug_ip_0003>`. For details about how to disassociate an IP address group from a listener, see :ref:`Configuring Access Control <en-us_elb_03_0003__section109371640175915>`.

Procedure
---------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. In the navigation pane on the left, choose **Elastic Load Balance** > **IP Address Groups**.
#. On the **IP Address Groups** page, locate the IP address group, and click **Delete** in the **Operation** column.
#. Click **Yes**.

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001794660485.png
