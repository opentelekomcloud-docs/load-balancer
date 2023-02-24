:original_name: elb_ug_zs_0005.html

.. _elb_ug_zs_0005:

Replacing a Certificate
=======================

Scenarios
---------

You need to bind a certificate when you add an HTTPS listener to a load balancer. If the certificate used by the load balancer has expired or needs to be replaced due to other reasons, you can replace the certificate.

If the certificate is also used by other services such as WAF, replace the certificate on all these services to prevent service unavailability.

.. note::

   Replacing certificates and private keys does not affect your applications.

Prerequisites
-------------

You have created a certificate by following the instructions in :ref:`Creating a Certificate <elb_ug_zs_0004__section26868475171830>`.

Binding a Certificate
---------------------

You can bind certificates when you add an HTTPS listener. For details, see :ref:`Adding an HTTPS Listener <elb_ug_jt_0009>`.


Replacing a Certificate
-----------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. On the **Listeners** tab page, locate the listener that you want to associate the backend server group with, click |image3| next to the listener name, and select **Modify Listener**.
#. Select a server certificate and click **Next**.
#. In the **Configure Backend Server Group** dialog box, click **Finish**.

.. |image1| image:: /_static/images/en-us_image_0000001211126503.png
.. |image2| image:: /_static/images/en-us_image_0000001417088430.png
.. |image3| image:: /_static/images/en-us_image_0000001447040000.png
