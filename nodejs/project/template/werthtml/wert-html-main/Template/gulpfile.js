// Gulp - Modules
var gulp            = require('gulp');
var clean           = require('gulp-clean');
var watch           = require('gulp-watch');
var mainBowerFiles  = require('gulp-main-bower-files');
var gulpFilter      = require('gulp-filter');
var gulpsync        = require('gulp-sync')(gulp);

// SASS & CSS - Modules
var sass            = require('gulp-sass');
var sourcemaps      = require('gulp-sourcemaps');
var cssmin          = require('gulp-cssmin');
var autoprefixer    = require('gulp-autoprefixer');
var rewriteCSS      = require('gulp-rewrite-css');
var replace         = require('gulp-replace');
var merge           = require('merge-stream');

// JS - Modules
var bump            = require('gulp-bump');
var concat          = require('gulp-concat');
var uglify          = require('gulp-uglify');
var header          = require('gulp-header');
var order           = require('gulp-order');
var pkg             = require('./package.json');

// Main Build Paths
var src_dir         = './src/';
var dist_dir        = './dist/';


/**
 * Config
 */
var config = {
	name:   'Wert Theme Plugins',
	banner: ['/*!',
		' * Wert Theme Plugins v<%= pkg.version %>',
		' * <%= pkg.description %>',
		' * Author: Copyright (c) <%= pkg.author.name %> <<%= pkg.author.twitter %>> <<%= pkg.author.url %>>',
		' * Url: <%= pkg.homepage %>',
		' * License: <%= pkg.license %>',
		' */',
		''].join('\n')
};

/**
 * CSS
 */

// SCSS Files
gulp.task('compile:scss-unminified', function () {
	return gulp.src( [ src_dir + 'scss/style.scss' ] )
		.pipe( sass( { outputStyle: 'compact' } ).on( 'error', sass.logError ) )
		.pipe( autoprefixer( { browsers: ['last 2 versions'] } ) )
		.pipe( concat('style-unminified.css') )
		.pipe( replace('../font/', 'font/') )
		.pipe( gulp.dest( dist_dir ) );
});

gulp.task('compile:scss', function () {
	return gulp.src( [ src_dir + 'scss/style.scss' ] )
		.pipe( sourcemaps.init() )
		.pipe( sass( { outputStyle: 'compressed' } ).on( 'error', sass.logError ) )
		.pipe( autoprefixer( { browsers: ['last 2 versions'] } ) )
		.pipe( concat('style.css') )
		.pipe( sourcemaps.write() )
		.pipe( replace('../font/', 'font/') )
		.pipe( gulp.dest( dist_dir ) );
});

// Vendor CSS Files
gulp.task('compile:vendor_css', function () {
	return gulp.src( [
        	dist_dir + 'plugins/justifiedGallery/dist/css/justifiedGallery.css',
			dist_dir + 'plugins/lightgallery/dist/css/lightgallery.min.css'
		] )
		.pipe( rewriteCSS( { destination: dist_dir } ) )
		.pipe( concat('vendor.css') )
		.pipe( cssmin() )
		.pipe( gulp.dest( dist_dir ) );
});

/**
 * JS
 */
gulp.task('compile:js', gulpsync.sync( ['copy:bower_components'] ), function () {
	return gulp.src( [dist_dir + 'plugins/plugins.js', src_dir + 'js/vendor/*.js'] )
		.pipe( uglify({
			preserveComments: 'license',
			compress: true,
			mangle: false
		}))
		.pipe( concat('plugins.js') )
		.pipe( header(config.banner, { pkg: pkg }))
		.pipe( gulp.dest( dist_dir + 'plugins/' ) );
});


/**
 * Google Fonts
 */
gulp.task('compile:google-fonts', function () {
	var googleWebFonts = require('gulp-google-webfonts');

	var options = {
		fontsDir: './font/', // Relative to where the final generated CSS is - meaning Style.css in the root
		cssDir: './',
		cssFilename: '_google-fonts.scss'
	};

	return gulp.src( src_dir + 'fonts.list')
		.pipe(googleWebFonts(options))
		.pipe(gulp.dest( src_dir + 'scss/' ));
});

/**
 * File Copy
 */
gulp.task('copy:fonts', function() {
	gulp.src([src_dir + 'font/**/*', src_dir + 'scss/font/**/*']).pipe(gulp.dest( dist_dir + 'font/'));
});

gulp.task('copy:img', function() {
	gulp.src([ src_dir + 'img/**/*']).pipe(gulp.dest( dist_dir + 'img/'));
});

gulp.task('copy:html', function() {
	gulp.src([ src_dir + 'html/**/*']).pipe(gulp.dest( dist_dir ));
});

gulp.task('copy:js', function() {
	gulp.src( [ src_dir + 'js/**/*.js', '!' + src_dir +'js/vendor/*.js' ] ).pipe(gulp.dest( dist_dir + 'js/' ));
});

// Copy Static files
gulp.task('copy:all', function() {

	// Copy All Files
	gulp.start('copy:fonts');
	gulp.start('copy:js');
	gulp.start('copy:img');
	gulp.start('copy:html');

});


gulp.task('copy:bower_components', function() {
	var filterJS = gulpFilter('**/*.js', { restore: true });
	return gulp.src('./bower.json')
		.pipe(mainBowerFiles({
			overrides: {
				'modernizr': {
					main: 'modernizr.js'
				},
				'lightgallery': {
					main: [
						'./dist/js/lightgallery-all.min.js',
						'./dist/css/*.min.*',
						'./dist/fonts/*.*',
						'./dist/img/*.*'
					]
				},
				'tilt.js': {
					main: [
						'./dest/tilt.jquery.js'
					]
				}
			}
		}))
		.pipe(filterJS)
		.pipe(concat('plugins.js'))
		.pipe( uglify({
			preserveComments: 'license',
			compress: true,
			mangle: false
		}))
		.pipe( header(config.banner, { pkg: pkg }))
		.pipe(filterJS.restore)
		.pipe(gulp.dest( dist_dir + 'plugins/' ));
});

gulp.task('clean:dist', function () {
	return gulp.src( dist_dir, {read: false})
		.pipe( clean() );
});

/**
 * Watchers
 */
gulp.task('watch', function() {

	// watches CSS & SCSS files for changes
	gulp.watch( [src_dir + 'scss/**/*' ], ['compile:scss'] );

	// watches JS
	gulp.watch( [src_dir + 'js/**/*.js', '!' + src_dir + 'js/vendor/*.js'], ['copy:js']);
	gulp.watch( [src_dir + 'js/vendor/*.js'], ['compile:js']);

	// watches IMG files
	gulp.watch( [src_dir + 'img/**/*'], ['copy:img']);

	// watches HTML files
	gulp.watch( [src_dir + 'html/**/*'], ['copy:html']);

});


/**
 * Default Task
 */
gulp.task( 'default', gulpsync.sync( ['clean:dist', 'compile:js', 'compile:scss-unminified', 'compile:scss', 'compile:vendor_css', 'copy:all', 'watch' ] ) );




/**
 * Bump version
 */
/*
 var bumpVer = function (bumpType) {
 return gulp.src(['package.json', 'bower.json'])
 .pipe(bump({
 type: bumpType
 }))
 .pipe(gulp.dest('./'));
 };
 gulp.task('bump:patch', function () { return bumpVer('patch'); });
 gulp.task('bump:minor', function () { return bumpVer('minor'); });
 gulp.task('bump:major', function () { return bumpVer('major'); });
 */