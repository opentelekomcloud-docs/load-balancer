:original_name: elb_ug_jt_0022.html

.. _elb_ug_jt_0022:

TLS Security Policy
===================

Scenarios
---------

When you add HTTPS listeners, you can select appropriate security policies to improve security. A security policy is a combination of TLS protocols and cipher suites.

Adding a Security Policy
------------------------

#. Log in to the management console.

#. In the upper left corner of the page, click |image1| and select the desired region and project.

#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. Locate the load balancer and click its name.

#. Under **Listeners**, click **Add Listener**.

#. In the **Add Listener** dialog box, set **Frontend Protocol** to **HTTPS**.

#. In the **Add Listener** dialog box, expand **Advanced Settings** and select a security policy. :ref:`Table 1 <elb_ug_jt_0022__table1247813103533>` lists the security policies.

   .. _elb_ug_jt_0022__table1247813103533:

   .. table:: **Table 1** Security policies

      +----------------------------------------------------+-------------------------------------------------------------------------------------------------------------+-----------------+----------------------------------+
      | Security Policy                                    | Description                                                                                                 | TLS Versions    | Cipher Suites                    |
      +====================================================+=============================================================================================================+=================+==================================+
      | TLS-1-0                                            | TLS 1.0, TLS 1.1, and TLS 1.2 and supported cipher suites (high compatibility and moderate security)        | TLS 1.2         | -  ECDHE-RSA-AES256-GCM-SHA384   |
      |                                                    |                                                                                                             |                 | -  ECDHE-RSA-AES128-GCM-SHA256   |
      |                                                    |                                                                                                             | TLS 1.1         | -  ECDHE-ECDSA-AES256-GCM-SHA384 |
      |                                                    |                                                                                                             |                 | -  ECDHE-ECDSA-AES128-GCM-SHA256 |
      |                                                    |                                                                                                             | TLS 1.0         | -  AES128-GCM-SHA256             |
      |                                                    |                                                                                                             |                 | -  AES256-GCM-SHA384             |
      |                                                    |                                                                                                             |                 | -  ECDHE-ECDSA-AES128-SHA256     |
      |                                                    |                                                                                                             |                 | -  ECDHE-RSA-AES128-SHA256       |
      |                                                    |                                                                                                             |                 | -  AES128-SHA256                 |
      |                                                    |                                                                                                             |                 | -  AES256-SHA256                 |
      |                                                    |                                                                                                             |                 | -  ECDHE-ECDSA-AES256-SHA384     |
      |                                                    |                                                                                                             |                 | -  ECDHE-RSA-AES256-SHA384       |
      |                                                    |                                                                                                             |                 | -  ECDHE-ECDSA-AES128-SHA        |
      |                                                    |                                                                                                             |                 | -  ECDHE-RSA-AES128-SHA          |
      |                                                    |                                                                                                             |                 | -  ECDHE-RSA-AES256-SHA          |
      |                                                    |                                                                                                             |                 | -  ECDHE-ECDSA-AES256-SHA        |
      |                                                    |                                                                                                             |                 | -  AES128-SHA                    |
      |                                                    |                                                                                                             |                 | -  AES256-SHA                    |
      +----------------------------------------------------+-------------------------------------------------------------------------------------------------------------+-----------------+----------------------------------+
      | TLS-1-1                                            | TLS 1.1 and TLS 1.2 and supported cipher suites (moderate compatibility and moderate security)              | TLS 1.2         |                                  |
      |                                                    |                                                                                                             |                 |                                  |
      |                                                    |                                                                                                             | TLS 1.1         |                                  |
      +----------------------------------------------------+-------------------------------------------------------------------------------------------------------------+-----------------+----------------------------------+
      | TLS-1-2                                            | TLS 1.2 and supported cipher suites (moderate compatibility and high security)                              | TLS 1.2         |                                  |
      +----------------------------------------------------+-------------------------------------------------------------------------------------------------------------+-----------------+----------------------------------+
      | TLS-1-2-Strict                                     | Strict TLS 1.2 and supported cipher suites (low compatibility and ultra-high security)                      | TLS 1.2         | -  ECDHE-RSA-AES256-GCM-SHA384   |
      |                                                    |                                                                                                             |                 | -  ECDHE-RSA-AES128-GCM-SHA256   |
      |                                                    |                                                                                                             |                 | -  ECDHE-ECDSA-AES256-GCM-SHA384 |
      |                                                    |                                                                                                             |                 | -  ECDHE-ECDSA-AES128-GCM-SHA256 |
      |                                                    |                                                                                                             |                 | -  AES128-GCM-SHA256             |
      |                                                    |                                                                                                             |                 | -  AES256-GCM-SHA384             |
      |                                                    |                                                                                                             |                 | -  ECDHE-ECDSA-AES128-SHA256     |
      |                                                    |                                                                                                             |                 | -  ECDHE-RSA-AES128-SHA256       |
      |                                                    |                                                                                                             |                 | -  AES128-SHA256                 |
      |                                                    |                                                                                                             |                 | -  AES256-SHA256                 |
      |                                                    |                                                                                                             |                 | -  ECDHE-ECDSA-AES256-SHA384     |
      |                                                    |                                                                                                             |                 | -  ECDHE-RSA-AES256-SHA384       |
      +----------------------------------------------------+-------------------------------------------------------------------------------------------------------------+-----------------+----------------------------------+
      | TLS-1-0-WITH-1-3 (for dedicated load balancers)    | TLS 1.0 and later, and supported cipher suites (ultra-high compatibility and low security)                  | TLS 1.3         | -  ECDHE-RSA-AES256-GCM-SHA384   |
      |                                                    |                                                                                                             |                 | -  ECDHE-RSA-AES128-GCM-SHA256   |
      |                                                    |                                                                                                             | TLS 1.2         | -  ECDHE-ECDSA-AES256-GCM-SHA384 |
      |                                                    |                                                                                                             |                 | -  ECDHE-ECDSA-AES128-GCM-SHA256 |
      |                                                    |                                                                                                             | TLS 1.1         | -  AES128-GCM-SHA256             |
      |                                                    |                                                                                                             |                 | -  AES256-GCM-SHA384             |
      |                                                    |                                                                                                             | TLS 1.0         | -  ECDHE-ECDSA-AES128-SHA256     |
      |                                                    |                                                                                                             |                 | -  ECDHE-RSA-AES128-SHA256       |
      |                                                    |                                                                                                             |                 | -  AES128-SHA256                 |
      |                                                    |                                                                                                             |                 | -  AES256-SHA256                 |
      |                                                    |                                                                                                             |                 | -  ECDHE-ECDSA-AES256-SHA384     |
      |                                                    |                                                                                                             |                 | -  ECDHE-RSA-AES256-SHA384       |
      |                                                    |                                                                                                             |                 | -  ECDHE-ECDSA-AES128-SHA        |
      |                                                    |                                                                                                             |                 | -  ECDHE-RSA-AES128-SHA          |
      |                                                    |                                                                                                             |                 | -  ECDHE-RSA-AES256-SHA          |
      |                                                    |                                                                                                             |                 | -  ECDHE-ECDSA-AES256-SHA        |
      |                                                    |                                                                                                             |                 | -  AES128-SHA                    |
      |                                                    |                                                                                                             |                 | -  AES256-SHA                    |
      |                                                    |                                                                                                             |                 | -  TLS_AES_128_GCM_SHA256        |
      |                                                    |                                                                                                             |                 | -  TLS_AES_256_GCM_SHA384        |
      |                                                    |                                                                                                             |                 | -  TLS_CHACHA20_POLY1305_SHA256  |
      |                                                    |                                                                                                             |                 | -  TLS_AES_128_CCM_SHA256        |
      |                                                    |                                                                                                             |                 | -  TLS_AES_128_CCM_8_SHA256      |
      +----------------------------------------------------+-------------------------------------------------------------------------------------------------------------+-----------------+----------------------------------+
      | TLS-1-2-FS-WITH-1-3 (for dedicated load balancers) | TLS 1.2 and later, and supported forward secrecy cipher suites (high compatibility and ultra-high security) | TLS 1.3         | -  ECDHE-RSA-AES256-GCM-SHA384   |
      |                                                    |                                                                                                             |                 | -  ECDHE-RSA-AES128-GCM-SHA256   |
      |                                                    |                                                                                                             | TLS 1.2         | -  ECDHE-ECDSA-AES256-GCM-SHA384 |
      |                                                    |                                                                                                             |                 | -  ECDHE-ECDSA-AES128-GCM-SHA256 |
      |                                                    |                                                                                                             |                 | -  ECDHE-ECDSA-AES128-SHA256     |
      |                                                    |                                                                                                             |                 | -  ECDHE-RSA-AES128-SHA256       |
      |                                                    |                                                                                                             |                 | -  ECDHE-ECDSA-AES256-SHA384     |
      |                                                    |                                                                                                             |                 | -  ECDHE-RSA-AES256-SHA384       |
      |                                                    |                                                                                                             |                 | -  TLS_AES_128_GCM_SHA256        |
      |                                                    |                                                                                                             |                 | -  TLS_AES_256_GCM_SHA384        |
      |                                                    |                                                                                                             |                 | -  TLS_CHACHA20_POLY1305_SHA256  |
      |                                                    |                                                                                                             |                 | -  TLS_AES_128_CCM_SHA256        |
      |                                                    |                                                                                                             |                 | -  TLS_AES_128_CCM_8_SHA256      |
      +----------------------------------------------------+-------------------------------------------------------------------------------------------------------------+-----------------+----------------------------------+
      | TLS-1-2-FS (for dedicated load balancers)          | TLS 1.2 and supported forward secrecy cipher suites (moderate compatibility and ultra-high security)        | TLS 1.2         | -  ECDHE-RSA-AES256-GCM-SHA384   |
      |                                                    |                                                                                                             |                 | -  ECDHE-RSA-AES128-GCM-SHA256   |
      |                                                    |                                                                                                             |                 | -  ECDHE-ECDSA-AES256-GCM-SHA384 |
      |                                                    |                                                                                                             |                 | -  ECDHE-ECDSA-AES128-GCM-SHA256 |
      |                                                    |                                                                                                             |                 | -  ECDHE-ECDSA-AES128-SHA256     |
      |                                                    |                                                                                                             |                 | -  ECDHE-RSA-AES128-SHA256       |
      |                                                    |                                                                                                             |                 | -  ECDHE-ECDSA-AES256-SHA384     |
      |                                                    |                                                                                                             |                 | -  ECDHE-RSA-AES256-SHA384       |
      +----------------------------------------------------+-------------------------------------------------------------------------------------------------------------+-----------------+----------------------------------+

   .. note::

      This table lists the cipher suites supported by ELB. Generally, clients also support multiple cipher suites. In actual use, the intersection of the cipher suites supported by ELB and those supported by clients is used, and the cipher suites supported by ELB take precedence.

#. Click **OK**.

Differences Between Security Policies
-------------------------------------

.. table:: **Table 2** Differences between the security policies

   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+
   | Security Policy               | TLS-1-0 | TLS-1-1 | TLS-1-2 | TLS-1-2-Strict | TLS-1-0-WITH-1-3 | TLS-1-2-FS-WITH-1-3 | TLS-1-2-FS |
   +===============================+=========+=========+=========+================+==================+=====================+============+
   | TLS versions                  |         |         |         |                |                  |                     |            |
   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+
   | TLS 1.3                       | ``-``   | ``-``   | ``-``   | ``-``          | Y                | Y                   | Y          |
   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+
   | TLS 1.2                       | Y       | Y       | Y       | Y              | Y                | Y                   | Y          |
   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+
   | TLS 1.1                       | Y       | Y       | ``-``   | ``-``          | Y                | ``-``               | ``-``      |
   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+
   | TLS 1.0                       | Y       | ``-``   | ``-``   | ``-``          | Y                | ``-``               | ``-``      |
   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+
   | Cipher suite                  |         |         |         |                |                  |                     |            |
   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+
   | EDHE-RSA-AES128-GCM-SHA256    | Y       | Y       | Y       | Y              | ``-``            | ``-``               | ``-``      |
   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+
   | ECDHE-RSA-AES256-GCM-SHA384   | Y       | Y       | Y       | Y              | Y                | Y                   | Y          |
   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+
   | ECDHE-RSA-AES128-SHA256       | Y       | Y       | Y       | Y              | Y                | Y                   | Y          |
   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+
   | ECDHE-RSA-AES256-SHA384       | Y       | Y       | Y       | Y              | Y                | Y                   | Y          |
   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+
   | AES128-GCM-SHA256             | Y       | Y       | Y       | Y              | Y                | ``-``               | ``-``      |
   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+
   | AES256-GCM-SHA384             | Y       | Y       | Y       | Y              | Y                | ``-``               | ``-``      |
   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+
   | AES128-SHA256                 | Y       | Y       | Y       | Y              | Y                | ``-``               | ``-``      |
   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+
   | AES256-SHA256                 | Y       | Y       | Y       | Y              | Y                | ``-``               | ``-``      |
   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+
   | ECDHE-RSA-AES128-SHA          | Y       | Y       | Y       | ``-``          | Y                | ``-``               | ``-``      |
   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+
   | ECDHE-RSA-AES256-SHA          | Y       | Y       | Y       | ``-``          | Y                | ``-``               | ``-``      |
   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+
   | AES128-SHA                    | Y       | Y       | Y       | ``-``          | Y                | ``-``               | ``-``      |
   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+
   | AES256-SHA                    | Y       | Y       | Y       | ``-``          | Y                | ``-``               | ``-``      |
   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+
   | ECDHE-ECDSA-AES128-GCM-SHA256 | Y       | Y       | Y       | Y              | Y                | Y                   | Y          |
   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+
   | ECDHE-ECDSA-AES128-SHA256     | Y       | Y       | Y       | Y              | Y                | Y                   | Y          |
   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+
   | ECDHE-ECDSA-AES128-SHA        | Y       | Y       | Y       | ``-``          | Y                | ``-``               | ``-``      |
   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+
   | ECDHE-ECDSA-AES256-GCM-SHA384 | Y       | Y       | Y       | Y              | Y                | Y                   | Y          |
   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+
   | ECDHE-ECDSA-AES256-SHA384     | Y       | Y       | Y       | Y              | Y                | Y                   | Y          |
   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+
   | ECDHE-ECDSA-AES256-SHA        | Y       | Y       | Y       | ``-``          | Y                | ``-``               | ``-``      |
   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+
   | ECDHE-RSA-AES128-GCM-SHA256   | ``-``   | ``-``   | ``-``   | ``-``          | Y                | Y                   | Y          |
   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+
   | TLS_AES_256_GCM_SHA384        | ``-``   | ``-``   | ``-``   | ``-``          | Y                | Y                   | Y          |
   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+
   | TLS_CHACHA20_POLY1305_SHA256  | ``-``   | ``-``   | ``-``   | ``-``          | Y                | Y                   | Y          |
   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+
   | TLS_AES_128_GCM_SHA256        | ``-``   | ``-``   | ``-``   | ``-``          | Y                | Y                   | Y          |
   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+
   | TLS_AES_128_CCM_8_SHA256      | ``-``   | ``-``   | ``-``   | ``-``          | Y                | Y                   | Y          |
   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+
   | TLS_AES_128_CCM_SHA256        | ``-``   | ``-``   | ``-``   | ``-``          | Y                | Y                   | Y          |
   +-------------------------------+---------+---------+---------+----------------+------------------+---------------------+------------+

Changing a Security Policy
--------------------------

When you change a security policy, ensure that the security group containing backend servers allows traffic from 100.125.0.0/16 to backend servers and allows ICMP packets for UDP health checks. Otherwise, backend servers will be considered unhealthy, and routing will be affected.

#. Log in to the management console.
#. In the upper left corner of the page, click |image3| and select the desired region and project.
#. Hover on |image4| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Click **Listeners**, locate the listener and click |image5| on the right of its name.
#. In the **Modify Listener** dialog box, expand **Advanced Settings** and change the security policy.
#. Click **OK**.

.. |image1| image:: /_static/images/en-us_image_0000001211126503.png
.. |image2| image:: /_static/images/en-us_image_0000001120894978.png
.. |image3| image:: /_static/images/en-us_image_0000001211126503.png
.. |image4| image:: /_static/images/en-us_image_0000001120894978.png
.. |image5| image:: /_static/images/en-us_image_0238408794.png
